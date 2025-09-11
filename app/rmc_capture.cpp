#include "rmc.h"
#include "rmc_internal.h"
#include "rmc_trace_file.h"
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

// Forward declarations
rmc_result_t write_data_to_file(void *data, uint64_t size);

rmc_result_t rmc_start_tracing(void) {
    auto& ctx = get_trace_context();
    TraceHeader header;
    ctx.file_stream.write((char *)&header, sizeof(TraceHeader));
    return rmc_result_t{true, "Tracing started"};
}

rmc_result_t rmc_end_tracing(void) {
    return rmc_deinit();
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

