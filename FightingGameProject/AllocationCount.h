#pragma once

#include <iostream>

#define ALLOC_COUNT true

#if ALLOC_COUNT

size_t numObjects = 0;
bool showAllocCount = false;
bool onlyShowZeroCount = false;

void* operator new(std::size_t size)
{
    ++numObjects;

    return std::malloc(size);
}

void operator delete(void* ptr)
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
