#include "rmc.h"
#include "rmc_internal.h"
#include "rmc_trace_file.h"
#include <fstream>
#include <iostream>

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