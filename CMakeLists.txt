cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_COMPILER "C:\\msys64\\mingw64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\msys64\\mingw64\\bin\\g++.exe")

project(CPPFG2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(CPPFG2 ${SOURCES})

target_link_libraries(CPPFG2 user32 gdi32 opengl32 gdiplus Shlwapi dwmapi)
