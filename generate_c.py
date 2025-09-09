import xml.etree.ElementTree as ET
import sys
import os

# Helper functions
def is_pointer(type_str):
    """Check if a type is a pointer (ends with '*')."""
    return type_str.endswith('*')

def get_base_type(type_str):
    """Get the base type by removing '*'."""
    result = type_str[:-1] if is_pointer(type_str) else type_str
    # Strip const qualifier for vector creation
    if result.startswith('const '):
        result = result[6:]
    return result

def is_basic_type(type_str, struct_names):
    """Check if a type is basic (not a struct or pointer)."""
    # void type is not serializable
    if 'void' in type_str:
        return False
    # Check for undefined internal raylib types
    if type_str in ['rAudioBuffer', 'rAudioProcessor']:
        return False
    return not is_pointer(type_str) and type_str not in struct_names

def get_cpp_param_type(param, struct_names):
    """Determine C++ parameter type for function signatures."""
    ptype = param['type']
    if is_pointer(ptype):
        base_type = get_base_type(ptype)
        # Don't add const if it's already there
        if base_type.startswith('const '):
            return f"{base_type}*"
        else:
            return f"const {base_type}*"
    elif ptype in struct_names:
        return f"const {ptype}&"
    else:
        return ptype

def parse_api(xml_file):
    """Parse XML into an API dictionary."""
    tree = ET.parse(xml_file)
    root = tree.getroot()
    api_name = root.get('name', 'API')  # Default to 'API' if name is missing
    module = root.find('module')
    header = module.get('header')
    structs = [
        {
            'name': t.get('name'),
            'members': [
                {'name': p.get('name'), 'type': p.get('type'), 'length': p.get('length')}
                for p in t.findall('param')
            ]
        }
        for t in module.findall('struct')
    ]
    functions = [
        {
            'name': f.get('name'),
            'return_type': f.get('return_type'),
            'params': [
                {'name': p.get('name'), 'type': p.get('type'), 'length': p.get('length')}
                for p in f.findall('param')
            ]
        }
        for f in module.findall('func')
    ]
    return {'api_name': api_name, 'header': header, 'structs': structs, 'functions': functions}

def generate_struct_serialization(struct, struct_names):
    """Generate serialization function for a struct."""
    code = f"void serialize_{struct['name']}(const {struct['name']}& s) {{\n"
    for m in struct['members']:
        mtype, mname, length = m['type'], m['name'], m.get('length')
        if not is_pointer(mtype):
            if length is not None and length != 'null_terminated':
                # Fixed-size array member (e.g., Matrix[2], float[2])
                length_code = f"s.{length}" if any(mem['name'] == length for mem in struct['members']) else length
                code += f"    for(int i = 0; i < {length_code}; i++) {{ \n"
                if is_basic_type(mtype, struct_names):
                    code += f"        serialize_le(s.{mname}[i]);\n"
                else:
                    code += f"        serialize_{mtype}(s.{mname}[i]);\n"
                code += "    }\n"
            elif is_basic_type(mtype, struct_names):
                code += f"    serialize_le(s.{mname});\n"
            else:
                code += f"    serialize_{mtype}(s.{mname});\n"
        else:
            base_type = get_base_type(mtype)
            # Skip void* and undefined types
            if 'void' in base_type or base_type in ['rAudioBuffer', 'rAudioProcessor']:
                code += f"    // Skipping {mname} (type: {mtype}) - not serializable\n"
                continue
            
            if length is None:
                if is_basic_type(base_type, struct_names):
                    code += f"    serialize_le(*s.{mname});\n"
                else:
                    code += f"    serialize_{base_type}(*s.{mname});\n"
            elif length == 'null_terminated':
                # Handle null-terminated strings
                if mtype == 'const char*' or mtype == 'char*':
                    code += f"    int length_{mname} = strlen(s.{mname}) + 1;\n    serialize_le(length_{mname});\n"
                    code += f"    for(int i = 0; i < length_{mname}; i++) {{\n"
                    code += f"        serialize_le(s.{mname}[i]);\n"
                    code += "    }\n"
                else:
                    # Fallback to single element for other pointer types
                    if is_basic_type(base_type, struct_names):
                        code += f"    serialize_le(*s.{mname});\n"
                    else:
                        code += f"    serialize_{base_type}(*s.{mname});\n"
            else:
                length_code = f"s.{length}" if any(mem['name'] == length for mem in struct['members']) else length
                code += f"    serialize_le({length_code});\n"
                code += f"    for(int i = 0; i < {length_code}; i++) {{ \n"
                if is_basic_type(base_type, struct_names):
                    code += f"        serialize_le(s.{mname}[i]);\n"
                else:
                    code += f"        serialize_{base_type}(s.{mname}[i]);\n"
                code += "    }\n"
    code += "}\n"
    return code

def generate_struct_deserialization(struct, struct_names):
    """Generate deserialization function for a struct."""
    code = f"{struct['name']} deserialize_{struct['name']}() {{\n"
    code += f"    {struct['name']} s;\n"
    for m in struct['members']:
        mtype, mname, length = m['type'], m['name'], m.get('length')
        if not is_pointer(mtype):
            if length is not None and length != 'null_terminated':
                # Fixed-size array member (e.g., Matrix[2], float[2])
                length_code = f"s.{length}" if any(mem['name'] == length for mem in struct['members']) else length
                code += f"    for(int i = 0; i < {length_code}; i++) {{ \n"
                if is_basic_type(mtype, struct_names):
                    code += f"        s.{mname}[i] = deserialize_le<{mtype}>();\n"
                else:
                    code += f"        s.{mname}[i] = deserialize_{mtype}();\n"
                code += "    }\n"
            elif is_basic_type(mtype, struct_names):
                code += f"    s.{mname} = deserialize_le<{mtype}>();\n"
            else:
                code += f"    s.{mname} = deserialize_{mtype}();\n"
        else:
            base_type = get_base_type(mtype)
            # Skip void* and undefined types
            if 'void' in base_type or base_type in ['rAudioBuffer', 'rAudioProcessor']:
                code += f"    // Skipping {mname} (type: {mtype}) - not deserializable\n"
                code += f"    s.{mname} = nullptr;\n"
                continue
            
            if length is None:
                code += f"    s.{mname} = new {base_type};\n"
                if is_basic_type(base_type, struct_names):
                    code += f"    *s.{mname} = deserialize_le<{base_type}>();\n"
                else:
                    code += f"    *s.{mname} = deserialize_{base_type}();\n"
            elif length == 'null_terminated':
                # Handle null-terminated strings
                if mtype == 'const char*' or mtype == 'char*':
                    code += f"    int length_{mname} = deserialize_le<int>();\n"
                    code += f"    s.{mname} = new char[length_{mname}];\n"
                    code += f"    for(int i = 0; i < length_{mname}; i++) {{\n"
                    code += f"        s.{mname}[i] = deserialize_le<char>();\n"
                    code += "    }\n"
                else:
                    # Fallback to single element for other pointer types
                    code += f"    s.{mname} = new {base_type};\n"
                    if is_basic_type(base_type, struct_names):
                        code += f"    *s.{mname} = deserialize_le<{base_type}>();\n"
                    else:
                        code += f"    *s.{mname} = deserialize_{base_type}();\n"
            else:
                code += f"    int length_{mname} = deserialize_le<int>();\n"
                if any(mem['name'] == length for mem in struct['members']):
                    code += f"    s.{length} = length_{mname};\n"
                code += f"    s.{mname} = new {base_type}[length_{mname}];\n    for(int i = 0; i < length_{mname}; i++) {{\n"
                if is_basic_type(base_type, struct_names):
                    code += f"        s.{mname}[i] = deserialize_le<{base_type}>();\n"
                else:
                    code += f"        s.{mname}[i] = deserialize_{base_type}();\n"
                    
                code += "    }\n"
    code += "    return s;\n}\n"
    return code

def generate_function_serialization(func, func_id, struct_names, api_id):
    """Generate serialization function for an API function."""
    params = ', '.join([get_cpp_param_type(p, struct_names) + ' ' + p['name'] for p in func['params']])
    params_str = params if params else ""
    code = f"void serialize_{func['name']}({params_str}) {{\n"
    code += f"    rmc_start_function_trace(2, {func_id});\n"
    for p in func['params']:
        ptype, pname, length = p['type'], p['name'], p.get('length')
        if not is_pointer(ptype):
            if is_basic_type(ptype, struct_names):
                code += f"    serialize_le({pname});\n"
            else:
                code += f"    serialize_{ptype}({pname});\n"
        else:
            base_type = get_base_type(ptype)
            # Skip void* and undefined types
            if 'void' in base_type or base_type in ['rAudioBuffer', 'rAudioProcessor']:
                code += f"    // Skipping {pname} (type: {ptype}) - not serializable\n"
                continue
            if length is None:
                code += f"    serialize_{(base_type if not is_basic_type(base_type, struct_names) else 'le')}(*{pname});\n"
            elif length == 'null_terminated':
                # Handle null-terminated strings
                if ptype == 'const char*' or ptype == 'char*':
                    code += f"    int length_{pname} = strlen({pname}) + 1;\n    serialize_le(length_{pname});\n"
                    code += f"    for(int i = 0; i < length_{pname}; i++) {{\n"
                    code += f"        serialize_le({pname}[i]);\n"
                    code += "    }\n"
                else:
                    # Fallback to single element for other pointer types
                    code += f"    serialize_{(base_type if not is_basic_type(base_type, struct_names) else 'le')}(*{pname});\n"
            else:
                # Check if length is referencing an integer parameter
                length_param = next((p for p in func['params'] if p['name'] == length), None)
                if length_param and not is_basic_type(length_param['type'], struct_names):
                    # Length parameter is not an integer, treat as single pointer
                    code += f"    serialize_{(base_type if not is_basic_type(base_type, struct_names) else 'le')}(*{pname});\n"
                else:
                    code += f"    int length_{pname} = {length};\n    serialize_le(length_{pname});\n"
                    code += f"    for(int i = 0; i < length_{pname}; i++) {{\n"
                    code += f"        serialize_{(base_type if not is_basic_type(base_type, struct_names) else 'le')}({pname}[i]);\n"
                    code += "    }\n"
    code += "    rmc_end_function_trace();\n}\n"
    return code

def generate_init_cpp(api):
    """Generate initialization file for API registration."""
    api_name = api['api_name']
    
    # Generate a unique API ID based on the API name hash
    # Use a deterministic hash
    import hashlib
    api_id = int(hashlib.md5(api_name.encode()).hexdigest()[:8], 16)
    
    init_cpp = f'#include "trace_internal.h"\n'
    init_cpp += f'#include "{api_name}_deserialization.h"\n\n'
    init_cpp += f'// Auto-generated initialization for {api_name}\n'
    init_cpp += f'void dispatch_{api_name}_function_call(uint64_t function_id, const uint8_t* buffer, uint64_t buffer_size);\n\n'
    init_cpp += f'static bool {api_name}_initialized = false;\n\n'
    init_cpp += f'rmc_result_t init_{api_name}() {{\n'
    init_cpp += f'    if ({api_name}_initialized) {{\n'
    init_cpp += f'        return rmc_result_t{{true, "{api_name} already initialized"}};\n'
    init_cpp += f'    }}\n\n'
    init_cpp += f'    SystemInfo system_info;\n'
    init_cpp += f'    system_info.api_id = {api_id}U;\n'
    init_cpp += f'    system_info.name = "{api_name}";\n'
    init_cpp += f'    system_info.description = "Auto-generated {api_name} tracing API";\n'
    init_cpp += f'    system_info.dispatch_func = dispatch_{api_name}_function_call;\n\n'
    init_cpp += f'    rmc_result_t result = rmc_register_api(system_info);\n'
    init_cpp += f'    if (result.is_valid) {{\n'
    init_cpp += f'        {api_name}_initialized = true;\n'
    init_cpp += f'    }}\n'
    init_cpp += f'    return result;\n'
    init_cpp += f'}}\n'
    
    return init_cpp

def generate_code(api):
    """Generate content for the files with API name in filenames."""
    api_name = api['api_name']
    
    # Skip functions that are problematic for serialization
    problematic_functions = {'GenImageFontAtlas', 'UnloadTextLines'}
    api['functions'] = [f for f in api['functions'] if f['name'] not in problematic_functions]
    
    struct_names = [s['name'] for s in api['structs']]
    
    # Generate the same API ID as used in init
    # Use a deterministic hash
    import hashlib
    api_id = int(hashlib.md5(api_name.encode()).hexdigest()[:8], 16)

    # Serialization Header
    serialization_h = f"#ifndef {api_name.upper()}_SERIALIZATION_H\n#define {api_name.upper()}_SERIALIZATION_H\n\n"
    serialization_h += "#include <vector>\n#include <cstdint>\n#include <cstring>\n"
    serialization_h += f"#include \"{api['header']}\"\n"
    serialization_h += "#include \"trace_internal.h\"\n\n"
    
    for s in api['structs']:
        serialization_h += f"void serialize_{s['name']}(const {s['name']}& s);\n"
    for f in api['functions']:
        params = ', '.join([get_cpp_param_type(p, struct_names) + ' ' + p['name'] for p in f['params']])
        params_str = f"{params}" if params else ""
        serialization_h += f"void serialize_{f['name']}({params_str});\n"
    serialization_h += "\n#endif // " + api_name.upper() + "_SERIALIZATION_H\n"

    # Serialization Source
    serialization_cpp = f'#include "{api_name}_serialization.h"\n\n'
    for s in api['structs']:
        serialization_cpp += generate_struct_serialization(s, struct_names) + "\n"
    for i, f in enumerate(api['functions']):
        serialization_cpp += generate_function_serialization(f, i, struct_names, api_id) + "\n"

    # Deserialization Header
    deserialization_h = f"#ifndef {api_name.upper()}_DESERIALIZATION_H\n#define {api_name.upper()}_DESERIALIZATION_H\n\n"
    deserialization_h += "#include <vector>\n#include <cstdint>\n#include <cstring>\n"
    deserialization_h += f"#include \"{api['header']}\"\n"
    deserialization_h += "#include \"trace_internal.h\"\n\n"

    for s in api['structs']:
        deserialization_h += f"{s['name']} deserialize_{s['name']}();\n"
    deserialization_h += f"void dispatch_{api_name}_function_call(uint64_t id, const uint8_t* buffer, uint64_t buffer_size);\n"
    deserialization_h += "\n#endif // " + api_name.upper() + "_DESERIALIZATION_H\n"

    # Deserialization Source
    deserialization_cpp = f'#include "{api_name}_deserialization.h"\n\n'
    deserialization_cpp += "#include <iostream>\n\n"
    for s in api['structs']:
        deserialization_cpp += generate_struct_deserialization(s, struct_names) + "\n"
    deserialization_cpp += f"void dispatch_{api_name}_function_call(uint64_t id, const uint8_t* buffer, uint64_t buffer_size)" + "{\n"
    deserialization_cpp += f"    // Set up deserialization context\n"
    deserialization_cpp += f"    auto& ctx = get_trace_context();\n"
    deserialization_cpp += f"    ctx.parameter_stream.data.assign(buffer, buffer + buffer_size);\n"
    deserialization_cpp += f"    ctx.parameter_stream.read_offset = 0;\n\n"
    deserialization_cpp += "    switch(id) {\n"
    for i, f in enumerate(api['functions']):
        deserialization_cpp += f"        case {i}: // {f['name']}\n"
        deserialization_cpp += "        {\n"
        param_vars = []
        for p in f['params']:
            ptype, pname, length = p['type'], p['name'], p.get('length')
            if not is_pointer(ptype):
                if is_basic_type(ptype, struct_names):
                    deserialization_cpp += f"            {ptype} {pname} = deserialize_le<{ptype}>();\n"
                else:
                    deserialization_cpp += f"            {ptype} {pname} = deserialize_{ptype}();\n"
                param_vars.append(pname)
            else:
                base_type = get_base_type(ptype)
                # Skip void* and undefined types
                if 'void' in base_type or base_type in ['rAudioBuffer', 'rAudioProcessor']:
                    deserialization_cpp += f"            // Skipping {pname} (type: {ptype}) - not deserializable\n"
                    param_vars.append("nullptr")
                    continue
                if length is None:
                    temp = f"temp_{pname}"
                    if is_basic_type(base_type, struct_names):
                        deserialization_cpp += f"            {base_type} {temp} = deserialize_le<{base_type}>();\n"
                    else:
                        deserialization_cpp += f"            {base_type} {temp} = deserialize_{base_type}();\n"
                    param_vars.append(f"&{temp}")
                elif length == 'null_terminated':
                    # Handle null-terminated strings
                    if ptype == 'const char*' or ptype == 'char*':
                        temp = f"temp_{pname}"
                        deserialization_cpp += f"            int length_{pname} = deserialize_le<int>();\n"
                        deserialization_cpp += f"            std::vector<char> {temp}(length_{pname});\n"
                        deserialization_cpp += f"            for(int i = 0; i < length_{pname}; i++) {{\n"
                        deserialization_cpp += f"                {temp}[i] = deserialize_le<char>();\n"
                        deserialization_cpp += "            }\n"
                        param_vars.append(f"{temp}.data()")
                    else:
                        # Fallback to single element for other pointer types
                        temp = f"temp_{pname}"
                        if is_basic_type(base_type, struct_names):
                            deserialization_cpp += f"            {base_type} {temp} = deserialize_le<{base_type}>();\n"
                        else:
                            deserialization_cpp += f"            {base_type} {temp} = deserialize_{base_type}();\n"
                        param_vars.append(f"&{temp}")
                else:
                    # Check if length is referencing an integer parameter  
                    length_param = next((p for p in f['params'] if p['name'] == length), None)
                    if length_param and not is_basic_type(length_param['type'], struct_names):
                        # Length parameter is not an integer, treat as single pointer
                        temp = f"temp_{pname}"
                        if is_basic_type(base_type, struct_names):
                            deserialization_cpp += f"            {base_type} {temp} = deserialize_le<{base_type}>();\n"
                        else:
                            deserialization_cpp += f"            {base_type} {temp} = deserialize_{base_type}();\n"
                        param_vars.append(f"&{temp}")
                    else:
                        temp = f"temp_{pname}"
                        deserialization_cpp += f"            int length_{pname} = deserialize_le<int>();\n"
                        deserialization_cpp += f"            std::vector<{base_type}> {temp}(length_{pname});\n"
                        deserialization_cpp += f"            for(int i = 0; i < length_{pname}; i++) {{\n"
                        if is_basic_type(base_type, struct_names):
                            deserialization_cpp += f"                {temp}[i] = deserialize_le<{base_type}>();\n"
                        else:
                            deserialization_cpp += f"                {temp}[i] = deserialize_{base_type}();\n"
                        deserialization_cpp += "            }\n"
                        param_vars.append(f"{temp}.data()")
        call = f"{f['name']}({', '.join(param_vars)})"
        if f['return_type'] == 'void':
            deserialization_cpp += f"            {call};\n"
        else:
            deserialization_cpp += f"            {f['return_type']} result = {call};\n"
        deserialization_cpp += "            break;\n"
        deserialization_cpp += "        }\n"
    deserialization_cpp += "        default:\n            std::cout << \"Unknown function ID: \" << id << std::endl;\n            break;\n"
    deserialization_cpp += "    }\n}\n"

    # Return a dictionary with filenames and their content
    return {
        f"{api_name}_serialization.h": serialization_h,
        f"{api_name}_serialization.cpp": serialization_cpp,
        f"{api_name}_deserialization.h": deserialization_h,
        f"{api_name}_deserialization.cpp": deserialization_cpp,
        f"{api_name}_init.cpp": generate_init_cpp(api)
    }

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python generate_c.py <xml_file>")
        sys.exit(1)
    xml_file = sys.argv[1]
    api = parse_api(xml_file)
    code_files = generate_code(api)
    xml_dir = os.path.dirname(xml_file)
    for filename, content in code_files.items():
        output_path = os.path.join(xml_dir, filename)
        with open(output_path, 'w') as f:
            f.write(content)
        print(f"Generated {output_path}")