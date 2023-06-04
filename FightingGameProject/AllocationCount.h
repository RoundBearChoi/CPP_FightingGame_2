#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>

size_t numObjects = 0;
bool showAllocationCount = false;

void* operator new(std::size_t size)
{
    ++numObjects;
    
    //std::cout << "Allocating " << size << " bytes" << std::endl;
    
    return std::malloc(size);
}

void operator delete(void* ptr)
{
    --numObjects;
    
    std::free(ptr);

    if (showAllocationCount)
    {
        std::cout << "allocation count: " << numObjects << std::endl;;
    }
}