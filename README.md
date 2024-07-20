# CPPFG2 by Roundbeargames

Indie game developer from South Korea
<br>
https://youtube.com/roundbeargames

<br>

# Windows 10 Build

You should already be familiar with CMake.
<br>
I'm using [MSYS2](https://www.msys2.org/) to install packages. 
<br>
```
pacman -Syu
pacman -Su
pacman -S mingw-w64-x86_64-cmake
pacman -S mingw-w64-x86_64-ninja
pacman -S mingw-w64-x86_64-gcc
```

<br>

Make sure to add path for the packages.
<br>

![system_path](screenshots/system_path_new.png)

<br>
<br>

Clone repository and build.
<br>
*If you look at my CMakeLists.txt you'll see that I'm using GCC.*

```
git clone https://github.com/RoundBearChoi/CPP_FightingGame_2
cd CPP_FightingGame_2

mkdir build
cd build

cmake -G "Ninja" ..
ninja
```

<br>

![running_clang](screenshots/run_exe_file.png)

<br>

# License (OLC-3)

This project uses olcPixelGameEngine by OneLoneCoder

<br>

Copyright 2018, 2019, 2020, 2021 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions or derivations of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions or derivative works in binary form must reproduce the above copyright notice. This list of conditions and the following disclaimer must be reproduced in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
