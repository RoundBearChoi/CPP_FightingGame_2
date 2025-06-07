# CPP Fighting Game 2

Developed by Roundbeargames, indie game developer based in South Korea.
<br>
Follow the development journey on [YouTube](https://youtube.com/roundbeargames).

## Overview

CPPFG2 is a 2D fighting game built in C++. This repository contains source code and build instructions for compiling and running on Windows 10.

## Prerequisites

Ensure you have the following:
- Windows 10
- [MSYS2](https://www.msys2.org/) with MINGW64 environment
- Git

## Installation

### 1. MSYS2 and Required Packages

- Install [MSYS2](https://www.msys2.org/) and open MINGW64 shell.
- Update package database and install required tools:

```bash
pacman -Syu
pacman -Su
pacman -S mingw-w64-x86_64-cmake
pacman -S mingw-w64-x86_64-ninja
pacman -S mingw-w64-x86_64-clang
pacman -S mingw-w64-x86_64-libc++
```

### 2. Clone and Build Repository

```bash
git clone https://github.com/RoundBearChoi/CPP_FightingGame_2
cd CPP_FightingGame_2
```

- Create build directory and generate build files:

```bash
mkdir build
cd build
cmake -G "Ninja" ..
```

- Compile project:

```bash
ninja
```

- Run .exe file

## Project Configuration

For detailed build configuration, refer to [CMakeLists.txt](https://github.com/RoundBearChoi/CPP_FightingGame_2/blob/main/CMakeLists.txt) file in the repository.

## License

This project is licensed under OLC-3 License. Below is the full license text:

**OLC-3 License**
Copyright 2018 - 2024 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions or derivations of source code must retain the above copyright notice, this list of conditions, and the following disclaimer.
2. Redistributions or derivative works in binary form must reproduce the above copyright notice, this list of conditions, and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request on the [GitHub repository](https://github.com/RoundBearChoi/CPP_FightingGame_2) for any bug fixes, features, or improvements.

## Contact

For inquiries, reach out via the [YouTube channel](https://youtube.com/roundbeargames) or create an issue on the GitHub repository.
