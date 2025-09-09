#pragma once
#include "trace.h"
#include "trace_file.h"
#include <map>
#include <vector>
#include <cstdint>
#include <fstream>

// Function pointer type for API dispatch functions
typedef void (*api_dispatch_func_t)(uint64_t function_id, const uint8_t* buffer, uint64_t buffer_size);

struct SystemInfo {
  uint32_t api_id;
  const char* name;
  const char* description;
  api_dispatch_func_t dispatch_func;
};

struct BlockParameterStream {
    BlockHeader header{};
    std::vector<uint8_t> data;
    size_t read_offset{0};
};

struct rmc_context {
    rmc_mode_t mode{};
    std::string filename{};
    std::fstream file_stream{};
    BlockParameterStream parameter_stream{};
    std::map<uint16_t, SystemInfo> registered_apis{};
    
    bool is_capturing() const { return mode == TMC_MODE_CAPTURE; }
    bool is_replaying() const { return mode == TMC_MODE_REPLAY; }
};

template <typename T>
T deserialize_le() {
    auto& ctx = get_trace_context();
    auto& buffer = ctx.parameter_stream.data;
    T value;
    std::memcpy(&value, &buffer[ctx.parameter_stream.read_offset], sizeof(T));
    ctx.parameter_stream.read_offset += sizeof(T);
    return value;
}

template <typename T>
void serialize_le(T value) {
    auto& data = get_trace_context().parameter_stream.data;
    data.insert(data.end(), reinterpret_cast<const uint8_t*>(&value), reinterpret_cast<const uint8_t*>(&value) + sizeof(T));
}

rmc_context& get_trace_context();

rmc_result_t rmc_start_function_trace(uint16_t api_id, uint16_t function_id);

rmc_result_t rmc_end_function_trace(void) ;

// API registration function
rmc_result_t rmc_register_api(const SystemInfo& system_info);

