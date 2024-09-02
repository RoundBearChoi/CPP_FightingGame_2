#pragma once

#include <iostream>
#include <random>

namespace RB
{
    class RandomGenerator
    {
    public:
        RandomGenerator() : gen(rd()) {} // Initialize automatically
        ~RandomGenerator() = default;

        void Init();
        int GetRand(int min, int max);

    private:
        std::random_device rd;
        std::mt19937 gen;
    };
}
