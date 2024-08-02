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

    void RenderRotationObj::SetStart(float start)
    {
        if (_processedFrames == 0)
		{
			_start = start;
	
			std::cout << std::endl;
			std::cout << "setting start rotation: " << start  << std::endl;
	
			_end = start + _totalRotation;
	
			std::cout << "setting end rotation: " << _end << std::endl;
		}
    }

    float RenderRotationObj::GetRotation()
    {
        // temp - only linear for now
        
        if (_processedFrames == 0)
        {
            return 0.0f;   
        }

        float perFrame = _totalRotation / (float)_totalFrames;
        
        float result = perFrame * float(_processedFrames + 1);
        
        //std::cout << "start + result.. " << _start + result << std::endl;

        return _start + result;
    }
}
