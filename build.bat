@echo off
REM Build script for ReplayMyC on Windows

set BUILD_TYPE=%1
if "%BUILD_TYPE%"=="" set BUILD_TYPE=Release

echo Building ReplayMyC (%BUILD_TYPE%)...

REM Create build directory
if not exist build mkdir build
cd build

REM Configure with CMake
cmake -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ..
if %errorlevel% neq 0 (
    echo CMake configuration failed!
    exit /b 1
)

REM Build
cmake --build . --config %BUILD_TYPE%
if %errorlevel% neq 0 (
    echo Build failed!
    exit /b 1
)

echo.
echo Build completed!
echo Executables are in: %cd%\bin\
echo.
echo To run the raylib example:
echo   .\bin\run_raylib_example.bat
echo.
echo To run manually:
echo   REM Capture mode:
echo   .\bin\raylib_test.exe capture trace.bin
echo   REM Replay mode:
echo   .\bin\raylib_test.exe replay trace.bin