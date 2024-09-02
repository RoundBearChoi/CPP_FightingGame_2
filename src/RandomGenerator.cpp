#include "RandomGenerator.h"

namespace RB
{
    void RandomGenerator::Init()
    {
        gen.seed(rd());
    }

    int RandomGenerator::GetRand(int min, int max)
    {
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
}
