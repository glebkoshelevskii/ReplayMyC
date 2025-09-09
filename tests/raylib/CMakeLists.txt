# Raylib example CMakeLists.txt

# Try to find raylib
find_package(raylib QUIET)

if(NOT raylib_FOUND)
    # If raylib not found, try to use the external submodule
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../external/raylib/CMakeLists.txt)
        message(STATUS "Using raylib submodule")
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../external/raylib raylib_build)
    else()
        message(FATAL_ERROR "raylib not found. Please install raylib or initialize the submodule with: git submodule update --init --recursive")
    endif()
endif()

# Create raylib tracing example executable
add_executable(raylib_test
    raylib_test.cpp
    raylib_serialization.cpp
    raylib_deserialization.cpp
    raylib_init.cpp
)

# Link libraries
target_link_libraries(raylib_test 
    trace
    raylib
)

# Include directories
target_include_directories(raylib_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

# Set target properties
set_target_properties(raylib_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy example usage script
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/run_example.sh.in
    ${CMAKE_BINARY_DIR}/bin/run_raylib_example.sh
    @ONLY
)

if(WIN32)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/run_example.bat.in
        ${CMAKE_BINARY_DIR}/bin/run_raylib_example.bat
        @ONLY
    )
endif()