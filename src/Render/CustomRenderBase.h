#pragma once

namespace RB::Render
{
    class CustomRenderBase
    {
    public:
        virtual ~CustomRenderBase() {};

    public:
        virtual void OnFixedUpdate() = 0;
        virtual bool DoDelete();

    protected:
        int _totalFrames = 0;
        int _processedFrames = 0;
        float _start = 0.0f;
		float _end = 0.0f;
    };
}
