cmake_minimum_required(VERSION 3.12)

# Set the C and C++ compilers (Windows)
set(CMAKE_C_COMPILER "C:\\msys64\\mingw64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\msys64\\mingw64\\bin\\g++.exe")

# Project name
project(CPPFG2)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Disable optimizations and enable debug symbols for debugging
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

# Collect source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# Create the executable
add_executable(CPPFG2 ${SOURCES})

# Link libraries
target_link_libraries(CPPFG2 user32 gdi32 opengl32 gdiplus Shlwapi dwmapi)