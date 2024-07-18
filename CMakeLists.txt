cmake_minimum_required(VERSION 3.12)
project(CPPFG2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(CPPFG2 ${SOURCES})

target_link_libraries(CPPFG2 user32 gdi32 opengl32 Shlwapi gdiplus dwmapi)
