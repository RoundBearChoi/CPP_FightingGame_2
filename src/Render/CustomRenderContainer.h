#pragma once

#include <vector>

namespace RB::Render
{
    template <typename T>
    class CustomRenderContainer
    {
    protected:
        std::vector<T> _vec;
    };
}
