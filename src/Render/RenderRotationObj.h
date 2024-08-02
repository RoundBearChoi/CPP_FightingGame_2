#pragma once

#include <iostream>

#include "CustomRenderBase.h"

namespace RB::Render
{
    class RenderRotationObj : public CustomRenderBase
    {
    public:
        RenderRotationObj(int totalFrames, float totalRotation);

    public:
        void OnFixedUpdate() override;

    public:
        void SetStart(float start) override;
        float GetRotation();
        void SetLastRotation(float rotation);

    private:
        float _totalRotation = 0.0f;
        float _lastRotation = 0.0f;
    };
}
