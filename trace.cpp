#include "trace.h"
#include "trace_internal.h"
#include "trace_file.h"
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

// Forward declarations
rmc_result_t write_data_to_file(void *data, uint64_t size);

namespace {
    static rmc_context ctx;
}

rmc_context& get_trace_context() {
    return ctx;
}

rmc_result_t rmc_init(rmc_mode_t mode, const char* filename) {
    auto& ctx = get_trace_context();
    ctx.mode = mode;
    ctx.filename = filename;
    int file_mode = std::ios::binary;
    if (ctx.is_capturing()) {
        ctx.file_stream.open(ctx.filename, file_mode | std::ios::out);
    } else {
        ctx.file_stream.open(ctx.filename, file_mode | std::ios::in);
    }
    return ctx.file_stream.is_open() ? (rmc_result_t{true, "Initialized successfully"}) 
                                        : (rmc_result_t{false, "Failed to open trace file"});
}

rmc_result_t rmc_deinit(void) {
    auto& ctx = get_trace_context();
    if (ctx.file_stream.is_open()) {
        ctx.file_stream.close();
    }
    return rmc_result_t{true, "Deinitialized successfully"};
}

rmc_result_t rmc_start_tracing(void) {
    auto& ctx = get_trace_context();
    TraceHeader header;
    ctx.file_stream.write((char *)&header, sizeof(TraceHeader));
    return rmc_result_t{true, "Tracing started"};
}

rmc_result_t rmc_end_tracing(void) {
    return rmc_deinit();
}

rmc_result_t rmc_replay_trace(void) {
    auto& ctx = get_trace_context();
    if (!ctx.is_replaying()) {
        return rmc_result_t{false, "Not in replay mode"};
    }
    
    if (!ctx.file_stream.is_open()) {
        return rmc_result_t{false, "Trace file not open"};
    }
    
    // Read and validate header
    TraceHeader header;
    ctx.file_stream.read(reinterpret_cast<char*>(&header), sizeof(TraceHeader));
    if (ctx.file_stream.fail()) {
        return rmc_result_t{false, "Failed to read trace header"};
    }
    
    // Read and dispatch blocks
    while (true) {
        BlockHeader block_header;
        ctx.file_stream.read(reinterpret_cast<char*>(&block_header), sizeof(BlockHeader));
        if (ctx.file_stream.eof()) {
            break;
        }
        if (ctx.file_stream.fail()) {
            return rmc_result_t{false, "Failed to read block header"};
        }
        
        // Read block data
        std::vector<uint8_t> buffer(block_header.size);
        if (block_header.size > 0) {
            ctx.file_stream.read(reinterpret_cast<char*>(buffer.data()), block_header.size);
            if (ctx.file_stream.fail()) {
                return rmc_result_t{false, "Failed to read block data"};
            }
        }
        
        // Dispatch to appropriate API
        if (block_header.type == BlockType::function_call) {
            auto api_it = ctx.registered_apis.find(block_header.api_id);
            if (api_it != ctx.registered_apis.end()) {
                api_it->second.dispatch_func(block_header.call_id, buffer.data(), buffer.size());
            } else {
                std::cerr << "Warning: No API registered for system ID " << block_header.api_id << std::endl;
            }
        }
    }
    
    return rmc_result_t{true, "Trace replayed successfully"};
}

rmc_result_t rmc_start_function_trace(uint16_t api_id, uint16_t function_id) {
    auto& ctx = get_trace_context();
    ctx.parameter_stream.header.api_id = api_id;
    ctx.parameter_stream.header.call_id = function_id;
    ctx.parameter_stream.header.type = BlockType::function_call;
    return rmc_result_t{true, "Started function trace"};
}

rmc_result_t rmc_end_function_trace(void) {
    auto& ctx = get_trace_context();
    ctx.parameter_stream.header.size = ctx.parameter_stream.data.size();
    write_data_to_file(&ctx.parameter_stream.header, sizeof(ctx.parameter_stream.header));
    write_data_to_file(ctx.parameter_stream.data.data(),
                       ctx.parameter_stream.data.size());

    ctx.parameter_stream.header.call_id = 0;
    ctx.parameter_stream.header.api_id = 0;
    ctx.parameter_stream.header.type = BlockType::default;
    ctx.parameter_stream.data.clear();
    return rmc_result_t{true, "Ended function trace"};
}

rmc_result_t write_data_to_file(void *data, uint64_t size) {
    auto& ctx = get_trace_context();
    ctx.file_stream.write((char *)data, size);
    return rmc_result_t{true, "Wrote data to file"};
}

rmc_result_t rmc_register_api(const SystemInfo& system_info) {
    auto& ctx = get_trace_context();
    if (ctx.registered_apis.find(system_info.api_id) != ctx.registered_apis.end()) {
        return rmc_result_t{false, "API already registered with this ID"};
    }
    
    ctx.registered_apis[system_info.api_id] = system_info;
    return rmc_result_t{true, "API registered successfully"};
}

