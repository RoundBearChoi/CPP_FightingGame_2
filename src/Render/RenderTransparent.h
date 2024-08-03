#pragma once

#include <iostream>

#include "CustomRender.h"

namespace RB::Render
{
    class RenderTransparent : public CustomRender
    {
    public:
        RenderTransparent(int totalFrames, float totalRotation);

    public:
        void OnFixedUpdate() override;

    public:
        void SetStart(float start) override;
        float GetAmount() override;
    };
}
