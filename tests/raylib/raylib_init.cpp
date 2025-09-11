#include "rmc_internal.h"
#include "raylib_deserialization.h"

// Auto-generated initialization for raylib
void dispatch_raylib_function_call(uint64_t function_id, const uint8_t* buffer, uint64_t buffer_size);

static bool raylib_initialized = false;

rmc_result_t init_raylib() {
    if (raylib_initialized) {
        return rmc_result_t{true, "raylib already initialized"};
    }

    SystemInfo system_info;
    system_info.api_id = 1215888600U;
    system_info.name = "raylib";
    system_info.description = "Auto-generated raylib tracing API";
    system_info.dispatch_func = dispatch_raylib_function_call;

    rmc_result_t result = rmc_register_api(system_info);
    if (result.is_valid) {
        raylib_initialized = true;
    }
    return result;
}
