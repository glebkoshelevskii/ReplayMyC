#include "rmc_internal.h"

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
