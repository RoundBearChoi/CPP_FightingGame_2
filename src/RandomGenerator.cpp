#include "RandomGenerator.h"

namespace RB
{
    void RandomGenerator::Init()
    {
        gen.seed(rd());
    }

    int RandomGenerator::GetRand(int min, int max)
    {
        // both min and max are included in the range of possible values
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
}
