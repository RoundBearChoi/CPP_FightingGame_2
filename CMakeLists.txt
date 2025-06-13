cmake_minimum_required(VERSION 3.12)

if(WIN32)
    # Set the C and C++ compilers (Clang)
    set(CMAKE_C_COMPILER "C:\\msys64\\mingw64\\bin\\clang.exe")
    set(CMAKE_CXX_COMPILER "C:\\msys64\\mingw64\\bin\\clang++.exe")

    # Project name
    project(CPPFG2)

    # Set the C++ standard
    set(CMAKE_CXX_STANDARD 17)

    # Disable optimizations and enable debug symbols for debugging
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

    # Use libc++ standard library with Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -I/C/msys64/mingw64/include/c++/v1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -L/C/msys64/mingw64/lib")

    # Collect source files
    file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

    # Create the executable
    add_executable(CPPFG2 ${SOURCES})

    # Link libraries
    target_link_libraries(CPPFG2 user32 gdi32 opengl32 gdiplus Shlwapi dwmapi)

elseif(UNIX)
    # Compiler settings (Clang)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

    # Set project name
    project(CPPFG2)

    # Set the C++ standard
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    # Disable optimizations and enable debug symbols for debugging
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

    # Collect source files
    file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

    # Create the executable
    add_executable(CPPFG2 ${SOURCES})

    # Link necessary Linux libraries
    target_link_libraries(CPPFG2 X11 GL pthread png stdc++fs)

    # Additional settings for libc++
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")

else()
    message(FATAL_ERROR "I'm only doing Windows & Linux builds for now")
endif()
