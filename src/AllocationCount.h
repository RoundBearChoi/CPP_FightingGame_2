#pragma once

#include <iostream>

#ifdef __clang__
    #include <new>
    #define NOEXCEPT noexcept
#else
    #include <new>
    #define NOEXCEPT _GLIBCXX_USE_NOEXCEPT
#endif

#define ALLOC_COUNT true

#if ALLOC_COUNT

    extern size_t numObjects;
    extern bool showAllocCount;
    extern bool onlyShowZeroCount;

    void* operator new(std::size_t size);
    void operator delete(void* ptr) NOEXCEPT;

#endif
