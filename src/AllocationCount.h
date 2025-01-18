#pragma once

#include <iostream>
#include <cstdlib>
#include <mutex>

#ifdef __clang__
    #include <new>
    #define NOEXCEPT noexcept
#else
    #define NOEXCEPT 
#endif

extern int numObjects;
extern int numObjBeforePlayground;
extern bool showAllocCount;
extern std::mutex allocMutex;

#define ALLOC_COUNT true

#if ALLOC_COUNT
    void* operator new(std::size_t size);
    // operator delete function is declared with noexcept
    // function should match this declaration
    void operator delete(void* ptr) NOEXCEPT; 
#endif