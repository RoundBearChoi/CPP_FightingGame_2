#include "AllocationCount.h"

int numObjects = 0;
int numObjBeforePlayground = 0;
bool showAllocCount = false;
std::mutex allocMutex;

#if ALLOC_COUNT

    void* operator new(std::size_t size)
    {
        std::lock_guard<std::mutex> lock(allocMutex);
        ++numObjects;

        return std::malloc(size);
    }

    void operator delete(void* ptr) NOEXCEPT
    {
        std::lock_guard<std::mutex> lock(allocMutex);
        --numObjects;

        std::free(ptr);

        if (showAllocCount)
        {
            std::cout << "allocation count: " << numObjects << std::endl;; 
        }
    }

#endif