#pragma once
#include <iostream>

#define ALLOC_COUNT true

#if ALLOC_COUNT

size_t numObjects = 0;
bool showAllocCount = false;

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
        std::cout << "allocation count: " << numObjects << std::endl;;
    }
}

#endif
