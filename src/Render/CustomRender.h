#pragma once

#include <vector>

namespace RB::Render
{
    template <typename T>
    class CustomRender
    {
    protected:
        std::vector<T> _vec;
    };
}
