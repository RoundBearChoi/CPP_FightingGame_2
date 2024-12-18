#include "AllocationCount.h"

#if ALLOC_COUNT

    size_t numObjects = 0;
    bool showAllocCount = true;
    bool onlyShowZeroCount = true;

    void* operator new(std::size_t size)
    {
        ++numObjects;
        
        //std::cout << "allocation count: " << numObjects << std::endl;;

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
