#pragma once

namespace RB
{
    inline float Lerp(float a, float b, float f)
    {
        return a * (1.0f - f) + (b * f);
    }
}
