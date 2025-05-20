cmake_minimum_required(VERSION 3.12)

# Set project name once
project(CPPFG2)

if(WIN32)
    # Set the C and C++ compilers (Clang)
    set(CMAKE_C_COMPILER "C:\\msys64\\mingw64\\bin\\clang.exe")
    set(CMAKE_CXX_COMPILER "C:\\msys64\\mingw64\\bin\\clang++.exe")

    # Set the C++ standard
    set(CMAKE_CXX_STANDARD 17)

    # Disable optimizations and enable debug symbols for debugging
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

    # Use libc++ standard library with Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -I/C/msys64/mingw64/include/c++/v1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -L/C/msys64/mingw64/lib")

    # Collect source files
    file(GLOB_RECURSIVE SOURCES "src/*.cpp" "src/*.h")

    # Create the executable
    add_executable(CPPFG2 ${SOURCES})

    # Link libraries
    target_link_libraries(CPPFG2 user32 gdi32 opengl32 gdiplus Shlwapi dwmapi)

elseif(UNIX)
    # Set compilers before any project settings
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    # Ensure compilers exist
    if(NOT EXISTS ${CMAKE_C_COMPILER})
        message(FATAL_ERROR "Clang not found at /usr/bin/clang")
    endif()
    if(NOT EXISTS ${CMAKE_CXX_COMPILER})
        message(FATAL_ERROR "Clang++ not found at /usr/bin/clang++")
    endif()

    # Set the C++ standard
    set(CMAKE_CXX_STANDARD 17)

    # Disable optimizations and enable debug symbols for debugging
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

    # Collect source files
    file(GLOB_RECURSIVE SOURCES "src/*.cpp")
    # Set include directories
    target_include_directories(CPPFG2 PRIVATE src)

    # Create the executable
    add_executable(CPPFG2 ${SOURCES})

    # Find and link libraries
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(PNG REQUIRED)
    target_link_libraries(CPPFG2 PRIVATE X11::X11 OpenGL::GL pthread PNG::PNG)

    # Settings for libc++
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

else()
    message(FATAL_ERROR "I'm only doing Windows & Linux build for now")
endif()