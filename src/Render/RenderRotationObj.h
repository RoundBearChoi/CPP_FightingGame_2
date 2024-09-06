#pragma once

#include <iostream>

#include "CustomRender.h"

namespace RB::Render
{
    class RenderRotationObj : public CustomRender
    {
    public:
        RenderRotationObj(int totalFrames, OperationType operationType, float totalRotation);

    public:
        void OnFixedUpdate() override;

    public:
        void SetStart(float start) override;
    };
}
