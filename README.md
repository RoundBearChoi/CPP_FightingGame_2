# CPP Fighting Game 2

Developed by Roundbeargames, indie game developer based in South Korea

Follow the development journey on [YouTube](https://youtube.com/roundbeargames)

<br>

## Overview

CPPFG2 is a 2D fighting game built in C++

This repository contains source code and build instructions for compiling and running on Windows 10 and Linux (Ubuntu)

<br>

## Windows 10 Installation

### 1. Prerequisites

- [MSYS2](https://www.msys2.org/) with [MINGW64](https://www.mingw-w64.org/) environment
- Git

### 2. MSYS2 and Required Packages

Install [MSYS2](https://www.msys2.org/) and open MINGW64 shell  

Update package database and install required tools:

```bash
pacman -Syu
pacman -Su
pacman -S mingw-w64-x86_64-cmake
pacman -S mingw-w64-x86_64-ninja
pacman -S mingw-w64-x86_64-clang
pacman -S mingw-w64-x86_64-libc++
```

### 3. Clone and Build Repository

```bash
git clone https://github.com/RoundBearChoi/CPP_FightingGame_2
cd CPP_FightingGame_2
```

Create build directory and generate build files:

```bash
mkdir build
cd build
cmake -G "Ninja" ..
```

Compile project:

```bash
ninja
```

Run CPPFG2.exe

<br>

## Linux (Ubuntu) Installation

### 1. Prerequisites

- Git
- Clang
- CMake
- Ninja
- Development libraries: libX11, OpenGL (mesa), libpng, pthread, libc++

```bash
sudo apt update
sudo apt install git clang cmake ninja-build libx11-dev libgl1-mesa-dev libpng-dev libpthread-stubs0-dev libc++-dev libc++abi-dev
```

### 2. Clone and Build Repository

```bash
git clone https://github.com/RoundBearChoi/CPP_FightingGame_2
cd CPP_FightingGame_2
```

Create build directory and generate build files:

```bash
mkdir build
cd build
cmake -G "Ninja" ..
```

Compile project:

```bash
ninja
```

Run the executable:

```bash
./CPPFG2
```

<br>
<br>

## Project Configuration

For detailed build configuration, refer to [CMakeLists.txt](https://github.com/RoundBearChoi/CPP_FightingGame_2/blob/main/CMakeLists.txt) file in the repository

<br>
<br>

## License

This project is licensed under OLC-3 License. Below is the full license text:

**OLC-3 License**  
Copyright 2018 - 2024 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions or derivations of source code must retain the above copyright notice, this list of conditions, and the following disclaimer.
2. Redistributions or derivative works in binary form must reproduce the above copyright notice, this list of conditions, and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
