#pragma once

#include <iostream>

namespace RB::Render
{
    class CustomRender
    {
    public:
        virtual ~CustomRender() {};

    public:
        virtual void OnFixedUpdate() = 0;
        virtual void SetStart(float start) = 0;
        virtual float GetAmount();
        virtual void AddProcessedFrame();
        virtual bool DoDelete();
        virtual int GetProcessedFrameCount();

    protected:
        int _totalFrames = 0;
        int _processedFrames = 0;
        float _totalAmount = 0.0f;
        float _start = 0.0f;
		float _end = 0.0f;
    };
}
