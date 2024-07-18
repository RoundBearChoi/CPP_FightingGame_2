cmake_minimum_required(VERSION 3.12)
project(CPPFG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE SOURCES "FightingGameProject/*.cpp")

add_executable(CPPFG ${SOURCES})

target_link_libraries(CPPFG user32 gdi32 opengl32 Shlwapi stdc++fs gdiplus dwmapi)
