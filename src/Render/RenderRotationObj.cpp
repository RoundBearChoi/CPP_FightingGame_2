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
        
        float perFrame = _totalRotation / (float)_totalFrames;
        
        float result = perFrame * float(_processedFrames + 1);
        
        std::cout << "getting rotation.. " << result << std::endl;
        //std::cout << "total rotation.. " << _lastRotation + result << std::endl;

        return result;
        //return _lastRotation + result;
    }

    void RenderRotationObj::SetLastRotation(float rotation)
    {
        _lastRotation = rotation;
    }
}
