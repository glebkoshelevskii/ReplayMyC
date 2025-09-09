cmake_minimum_required(VERSION 3.16)
project(ReplayMyC VERSION 1.0.0 LANGUAGES CXX C)

# Add cmake modules path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add compiler flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
endif()

# Create trace library
add_library(trace STATIC
    trace.cpp
    trace.h
    trace_internal.h
    trace_file.h
)

target_include_directories(trace PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add examples subdirectory
add_subdirectory(tests/raylib)

# Install targets
install(TARGETS trace
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES
    trace.h
    trace_internal.h
    trace_file.h
    DESTINATION include
)

# Install Python tools
install(FILES
    generate_xml.py
    generate_c.py
    DESTINATION tools
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)