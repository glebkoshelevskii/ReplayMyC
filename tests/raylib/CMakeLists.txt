# Raylib example CMakeLists.txt

# Try to find raylib
find_package(raylib QUIET)

# Create raylib tracing example executable
add_executable(raylib_test
    raylib_test.cpp
    raylib_serialization.cpp
    raylib_deserialization.cpp
    raylib_init.cpp
)

# Link libraries
target_link_libraries(raylib_test 
    rmc_lib
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