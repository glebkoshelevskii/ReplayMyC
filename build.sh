#!/bin/bash
# Build script for ReplayMyC

set -e

# Default build type
BUILD_TYPE=${1:-Release}

echo "Building ReplayMyC (${BUILD_TYPE})..."

# Create build directory
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

# Configure with CMake
cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} ..

# Build
cmake --build . --parallel $(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

echo "Build completed!"
echo "Executables are in: $(pwd)/bin/"
echo
echo "To run the raylib example:"
echo "  ./bin/run_raylib_example.sh"
echo
echo "To run manually:"
echo "  # Capture mode:"
echo "  ./bin/raylib_test capture trace.bin" 
echo "  # Replay mode:"
echo "  ./bin/raylib_test replay trace.bin"