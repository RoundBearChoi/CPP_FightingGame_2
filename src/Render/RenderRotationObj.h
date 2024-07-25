#pragma once

#include "iAnimationObj.h"

namespace RB::Render
{
    class iAnimationObj; // forward declare

    class RenderRotationObj
    {
        public:
        RenderRotationObj(int totalFrames, float totalRotation);
        
        void OnFixedUpdate();

        float GetRotation();

        private:
        int _totalFrames = 0;
        float _totalRotation = 0.0f;
        int _processedFrames = 0;
		iAnimationObj* _owner = nullptr;
		float _start = 0.0f;
		float _end = 0.0f;
    };
}
