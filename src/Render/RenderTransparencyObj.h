#pragma once

#include <iostream>

#include "CustomRender.h"

namespace RB::Render
{
    class RenderTransparencyObj : public CustomRender
    {
    public:
        RenderTransparencyObj(int totalFrames, float totalTransparency);

    public:
        void OnFixedUpdate() override;

    public:
        void SetStart(float start) override;
        float GetAmount() override;
    };
}
