#pragma once

#include <iostream>

#ifdef __clang__
    #include <new>
    #define NOEXCEPT noexcept
#elif __GNUC__
    #include <new>
    #define NOEXCEPT _GLIBCXX_USE_NOEXCEPT
#else
    #define NOEXCEPT

#endif

#define ALLOC_COUNT true

#if ALLOC_COUNT

    extern size_t numObjects;
    extern bool showAllocCount;
    extern bool onlyShowZeroCount;

    void* operator new(std::size_t size);
    void operator delete(void* ptr) NOEXCEPT;

#endif