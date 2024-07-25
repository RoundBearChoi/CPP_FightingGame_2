#include "RenderRotationObj.h"

namespace RB::Render
{
    RenderRotationObj::RenderRotationObj(int totalFrames, float totalRotation)
    {
        _totalFrames = totalFrames;
        _totalRotation = totalRotation;
    }

    void RenderRotationObj::OnFixedUpdate()
    {

    }

    float RenderRotationObj::GetRotation()
    {
        // temp - only linear for now
        
        float oneFrame = _totalRotation / (float)_totalFrames;
        
        float result = oneFrame * float(_processedFrames + 1);
        
        //std::cout << "getting rotation.. " << result << std::endl;

        return result;
    }

    void RenderRotationObj::SetLastRotation(float rotation)
    {
        _lastRotation = rotation;
    }
}
