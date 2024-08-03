#pragma once

#include <iostream>

#include "CustomRender.h"

namespace RB::Render
{
    class RenderRotationObj : public CustomRender
    {
    public:
        RenderRotationObj(int totalFrames, float totalRotation);

    public:
        void OnFixedUpdate() override;

    public:
        void SetStart(float start) override;
        float GetAmount() override;

    //private:
    //    float _totalRotation = 0.0f;
    };
}
