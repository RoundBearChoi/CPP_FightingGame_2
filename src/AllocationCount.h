#pragma once

#include <iostream>

#ifdef __clang__
#include <new>
#define NOEXCEPT noexcept
#else
#include <new>
#define NOEXCEPT _GLIBCXX_USE_NOEXCEPT
#endif

// Rest of your code...


#define ALLOC_COUNT true
#if ALLOC_COUNT

size_t numObjects = 0;
bool showAllocCount = false;
bool onlyShowZeroCount = true;

void* operator new(std::size_t size)
{
    ++numObjects;

    return std::malloc(size);
}

void operator delete(void* ptr) NOEXCEPT
{
    --numObjects;

    std::free(ptr);

    if (showAllocCount)
    {
        if (onlyShowZeroCount && numObjects != 0)
        {
            // do nothing
        }
        else
        {
            std::cout << "allocation count: " << numObjects << std::endl;;
        }
    }
}

#endif
