#!/usr/bin/env python3
"""
C Header Parser to XML Generator
Parses C header files and generates XML descriptions of functions and structs.
"""

import re
import sys
import os
import xml.etree.ElementTree as ET
from xml.dom import minidom
import argparse

class CParser:
    def __init__(self):
        self.structs = []
        self.functions = []
        self.enums = []
        self.manual_review_needed = []
        
    def clean_code(self, content):
        """Remove comments and handle multi-line constructs"""
        # Remove single-line comments
        content = re.sub(r'//.*', '', content)
        # Remove multi-line comments
        content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
        # Remove preprocessor directives except includes
        content = re.sub(r'#(?!include).*', '', content)
        return content
    
    def parse_struct(self, match):
        """Parse a struct definition"""
        struct_name = match.group(1)
        body = match.group(2)
        
        struct = {
            'name': struct_name,
            'members': []
        }
        
        # Parse struct members - handle multiple members on same line like "float m0, m4, m8, m12;"
        # First, split by semicolons to get declarations
        declarations = [decl.strip() for decl in body.split(';') if decl.strip()]
        
        for decl in declarations:
            # Remove comments from the declaration
            decl = re.sub(r'//.*', '', decl).strip()
            if not decl:
                continue
            
            # Pattern to match type and comma-separated names
            # More specific pattern to handle multi-word types like "unsigned char"
            type_and_names_pattern = r'((?:unsigned\s+|signed\s+)?(?:long\s+)?(?:long\s+)?\w+)\s*(\*?)\s*([\w\s,\[\]]+)'
            match_decl = re.match(type_and_names_pattern, decl)
            
            if match_decl:
                member_type = match_decl.group(1).strip()
                pointer_marker = match_decl.group(2)
                names_part = match_decl.group(3).strip()
                
                # Handle pointer types
                if pointer_marker == '*':
                    member_type = member_type + '*'
                
                # Split names by comma and handle arrays
                name_parts = [name.strip() for name in names_part.split(',')]
                
                for name_part in name_parts:
                    name_part = name_part.strip()
                    if not name_part:
                        continue
                    
                    # Check for array syntax like "name[size]"
                    array_match = re.match(r'(\w+)(?:\[(\w+)\])?', name_part)
                    if array_match:
                        member_name = array_match.group(1)
                        array_size = array_match.group(2)
                        
                        member = {
                            'name': member_name,
                            'type': member_type
                        }
                        
                        # Handle array members
                        if array_size:
                            member['length'] = array_size
                        
                        struct['members'].append(member)
        
        return struct
    
    def parse_function(self, match):
        """Parse a function definition"""
        return_type = match.group(1).strip()
        func_name = match.group(2)
        params_str = match.group(3)
        
        function = {
            'name': func_name,
            'return_type': return_type,
            'params': []
        }
        
        # Parse parameters
        if params_str.strip() and params_str.strip() != 'void':
            # Split parameters by comma, but handle nested structures
            param_parts = []
            paren_count = 0
            current_param = ""
            
            for char in params_str:
                if char == ',' and paren_count == 0:
                    param_parts.append(current_param.strip())
                    current_param = ""
                else:
                    if char == '(':
                        paren_count += 1
                    elif char == ')':
                        paren_count -= 1
                    current_param += char
            
            if current_param.strip():
                param_parts.append(current_param.strip())
            
            for param_str in param_parts:
                param_str = param_str.strip()
                if not param_str or param_str == 'void':
                    continue
                
                # Parse parameter type and name
                param_match = re.match(r'(.+?)\s+(\w+)$', param_str)
                if param_match:
                    param_type = param_match.group(1).strip()
                    param_name = param_match.group(2)
                    
                    # Handle pointer types
                    if '*' in param_type:
                        param_type = param_type.replace('*', '').strip() + '*'
                    
                    param = {
                        'name': param_name,
                        'type': param_type
                    }
                    
                    function['params'].append(param)
        
        return function
    
    def infer_array_lengths(self):
        """Infer array lengths based on common patterns, add placeholders for unknown"""
        for func in self.functions:
            params = func['params']
            
            # Look for pointer + length patterns
            for i, param in enumerate(params):
                if param['type'].endswith('*'):
                    length_found = False
                    # Look for a length parameter
                    for j, other_param in enumerate(params):
                        if (other_param['name'] == 'length' or 
                            other_param['name'] == 'count' or
                            other_param['name'] == 'size'):
                            param['length'] = other_param['name']
                            length_found = True
                            break
                    
                    # If no length found, check for const char* (null-terminated string)
                    if not length_found:
                        if param['type'] == 'const char*' or param['type'] == 'char*':
                            param['length'] = 'null_terminated'
                        else:
                            param['length'] = f"1 /* TODO: Specify length for {param['name']} */"
                            self.manual_review_needed.append({
                                'type': 'function_param',
                                'function': func['name'],
                                'param': param['name'],
                                'param_type': param['type'],
                                'message': f"Array parameter '{param['name']}' in function '{func['name']}' needs length specification"
                            })
        
        # Handle struct members with pointers
        for struct in self.structs:
            for member in struct['members']:
                if member['type'].endswith('*'):
                    length_found = False
                    # Look for length member in same struct
                    for other_member in struct['members']:
                        if (other_member['name'] == 'length' or
                            other_member['name'] == 'count' or
                            other_member['name'] == 'size'):
                            member['length'] = other_member['name']
                            length_found = True
                            break
                    
                    # If no length found, check for const char* (null-terminated string)
                    if not length_found:
                        if member['type'] == 'const char*' or member['type'] == 'char*':
                            member['length'] = 'null_terminated'
                        else:
                            member['length'] = f"1 /* TODO: Specify length for {member['name']} */"
                            self.manual_review_needed.append({
                                'type': 'struct_member',
                                'struct': struct['name'],
                                'member': member['name'],
                                'member_type': member['type'],
                                'message': f"Array member '{member['name']}' in struct '{struct['name']}' needs length specification"
                            })
    
    
    def parse_enum(self, match):
        """Parse an enum definition"""
        enum_name = match.group(1) if match.group(1) else "Anonymous"
        body = match.group(2)
        
        enum = {
            'name': enum_name,
            'values': []
        }
        
        # Parse enum values
        # Handle both NAME = VALUE and just NAME formats
        value_pattern = r'(\w+)(?:\s*=\s*([^,\s}]+))?'
        current_value = 0
        
        for value_match in re.finditer(value_pattern, body):
            name = value_match.group(1)
            explicit_value = value_match.group(2)
            
            if explicit_value:
                # Try to parse the value (could be number, hex, or expression)
                value = explicit_value.strip()
                # If it's a simple integer, update current_value for auto-increment
                try:
                    current_value = int(value, 0)  # Supports hex with 0x prefix
                except ValueError:
                    # Keep the expression as-is if not a simple integer
                    pass
            else:
                value = str(current_value)
            
            enum['values'].append({
                'name': name,
                'value': value
            })
            
            current_value += 1
        
        return enum

    def parse_header(self, content):
        """Parse C header file content"""
        content = self.clean_code(content)
        
        # Parse enums - handle both typedef enum and regular enum
        enum_pattern = r'(?:typedef\s+)?enum\s*(?:(\w+)\s*)?\{([^}]+)\}(?:\s*(\w+))?'
        for match in re.finditer(enum_pattern, content):
            enum_name = match.group(1) or match.group(3)  # Name can be before or after {}
            if enum_name:
                enum = self.parse_enum(match)
                enum['name'] = enum_name
                self.enums.append(enum)
        
        # Parse structs - handle both "struct Name" and "typedef struct Name"
        struct_pattern = r'(?:typedef\s+)?struct\s+(\w+)\s*\{([^}]+)\}(?:\s*(\w+))?'
        for match in re.finditer(struct_pattern, content):
            struct_name = match.group(1) or match.group(3)  # Name can be before or after {}
            if struct_name:
                # Create a new match object for parse_struct with the correct groups
                class StructMatch:
                    def __init__(self, name, body):
                        self._name = name
                        self._body = body
                    def group(self, n):
                        if n == 1: return self._name
                        if n == 2: return self._body
                        return None
                
                struct_match = StructMatch(struct_name, match.group(2))
                struct = self.parse_struct(struct_match)
                self.structs.append(struct)
        
        # Parse functions - handle API prefixes like RLAPI, RAYLIB_API, etc.
        # Pattern matches: [API_PREFIX] return_type function_name(params) [;|{body}]
        func_pattern = r'(?:(\w+)\s+)?(\w+(?:\s*\*)*)\s+(\w+)\s*\(([^)]*)\)\s*(?:\{[^{}]*(?:\{[^{}]*\}[^{}]*)*\}|;)'
        for match in re.finditer(func_pattern, content, re.DOTALL):
            api_prefix = match.group(1)  # Could be RLAPI, RAYLIB_API, etc.
            return_type = match.group(2).strip()
            func_name = match.group(3)
            params_str = match.group(4)
            
            # Skip if this looks like a struct member or variable declaration
            line_start = content.rfind('\n', 0, match.start()) + 1
            line_prefix = content[line_start:match.start()].strip()
            
            # Skip if inside a struct or enum definition
            if '{' in line_prefix and '}' not in line_prefix:
                continue
                
            # Skip obvious non-functions (like struct/enum definitions, variable declarations)
            if func_name in [s['name'] for s in self.structs]:
                continue
            
            # Skip if return type looks like a struct member type or invalid
            if not return_type or return_type in ['struct', 'union', 'enum', 'typedef']:
                continue
            
            # Skip if it's actually a typedef or other declaration
            if api_prefix and api_prefix in ['typedef', 'struct', 'union', 'enum', 'static', 'extern']:
                continue
                
            # Create function object
            function = {
                'name': func_name,
                'return_type': return_type,
                'params': []
            }
            
            # Parse parameters using existing logic
            if params_str.strip() and params_str.strip() != 'void':
                # Split parameters by comma, but handle nested structures
                param_parts = []
                paren_count = 0
                current_param = ""
                
                for char in params_str:
                    if char == ',' and paren_count == 0:
                        param_parts.append(current_param.strip())
                        current_param = ""
                    else:
                        if char == '(':
                            paren_count += 1
                        elif char == ')':
                            paren_count -= 1
                        current_param += char
                
                if current_param.strip():
                    param_parts.append(current_param.strip())
                
                for param_str in param_parts:
                    param_str = param_str.strip()
                    if not param_str or param_str == 'void':
                        continue
                    
                    # Parse parameter type and name
                    # Handle cases like "const char *title", "int width", "Vector2* points"
                    param_match = re.match(r'(.+?)\s*\*?\s*(\w+)$', param_str)
                    if param_match:
                        param_type = param_match.group(1).strip()
                        param_name = param_match.group(2)
                        
                        # Handle pointer types - check if there was a * in the original string
                        if '*' in param_str:
                            # Remove any existing * from type and add it at the end
                            param_type = param_type.replace('*', '').strip() + '*'
                        
                        param = {
                            'name': param_name,
                            'type': param_type
                        }
                        
                        function['params'].append(param)
            
            self.functions.append(function)
        
        # Infer array lengths
        self.infer_array_lengths()

def create_xml(api_name, header_file, structs, functions, enums=None):
    """Create XML structure from parsed data"""
    root = ET.Element('api')
    root.set('name', api_name)
    root.set('version', '1.0')
    
    module = ET.SubElement(root, 'module')
    module.set('header', os.path.basename(header_file))
    
    # Add struct types
    for struct in structs:
        type_elem = ET.SubElement(module, 'struct')
        type_elem.set('name', struct['name'])
        
        for member in struct['members']:
            param_elem = ET.SubElement(type_elem, 'param')
            param_elem.set('name', member['name'])
            param_elem.set('type', member['type'])
            
            if 'length' in member:
                param_elem.set('length', member['length'])
    
    # Add enums
    if enums:
        for enum in enums:
            enum_elem = ET.SubElement(module, 'enum')
            enum_elem.set('name', enum['name'])
            
            for value in enum['values']:
                param_elem = ET.SubElement(enum_elem, 'param')
                param_elem.set('name', value['name'])
                param_elem.set('value', value['value'])
    
    # Add functions
    for func in functions:
        func_elem = ET.SubElement(module, 'func')
        func_elem.set('name', func['name'])
        func_elem.set('return_type', func['return_type'])
        
        for param in func['params']:
            param_elem = ET.SubElement(func_elem, 'param')
            param_elem.set('name', param['name'])
            param_elem.set('type', param['type'])
            
            if 'length' in param:
                param_elem.set('length', param['length'])
    
    return root

def prettify_xml(elem):
    """Return a pretty-printed XML string"""
    rough_string = ET.tostring(elem, 'unicode')
    reparsed = minidom.parseString(rough_string)
    return reparsed.toprettyxml(indent="  ")

def main():
    parser = argparse.ArgumentParser(description='Parse C header files and generate XML API descriptions')
    parser.add_argument('header_file', help='Input C header file')
    parser.add_argument('-o', '--output', help='Output XML file (default: same name as input with .xml extension)')
    parser.add_argument('-n', '--name', help='API name (default: derived from filename)')
    
    args = parser.parse_args()
    
    # Determine output file
    if args.output:
        output_file = args.output
    else:
        base_name = os.path.splitext(os.path.basename(args.header_file))[0]
        output_file = base_name + '.xml'
    
    # Determine API name
    if args.name:
        api_name = args.name
    else:
        api_name = os.path.splitext(os.path.basename(args.header_file))[0]
    
    # Parse header file
    try:
        with open(args.header_file, 'r', encoding='utf-8') as f:
            content = f.read()
    except UnicodeDecodeError:
        # Try with different encoding
        with open(args.header_file, 'r', encoding='latin1') as f:
            content = f.read()
    
    c_parser = CParser()
    c_parser.parse_header(content)
    
    # Create XML
    xml_root = create_xml(api_name, args.header_file, c_parser.structs, c_parser.functions, c_parser.enums)
    
    # Write XML file
    xml_string = prettify_xml(xml_root)
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(xml_string)
    
    print(f"Generated {output_file}")
    print(f"Found {len(c_parser.structs)} structs, {len(c_parser.enums)} enums, and {len(c_parser.functions)} functions")
    
    # Print manual review notifications
    if c_parser.manual_review_needed:
        print(f"\nWARNING: Manual review needed for {len(c_parser.manual_review_needed)} items:")
        for item in c_parser.manual_review_needed:
            print(f"  * {item['message']}")
        print(f"\nPlease edit {output_file} and replace the TODO placeholders with appropriate length specifications.")

if __name__ == "__main__":
    main()