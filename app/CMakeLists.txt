
add_library(rmc_lib STATIC
rmc_capture.cpp
rmc_replay.cpp
rmc_internal.h
rmc_trace_file.h
rmc.h
rmc.cpp
)

target_include_directories(rmc_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})