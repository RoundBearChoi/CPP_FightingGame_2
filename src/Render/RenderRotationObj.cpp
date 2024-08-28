#include "RenderRotationObj.h"

namespace RB::Render
{
    RenderRotationObj::RenderRotationObj(int totalFrames, float totalRotation)
    {
        _totalFrames = totalFrames;
        _totalAmount = totalRotation;
    }

    void RenderRotationObj::OnFixedUpdate()
    {
        
    }

    void RenderRotationObj::SetStart(float start)
    {
        if (_processedFrames == 0)
		{
            //std::cout << "start is " << start << std::endl;

			_start = start;
	
			//std::cout << std::endl;
			//std::cout << "setting start rotation: " << start  << std::endl;
	
			_end = start + _totalAmount;
	
			//std::cout << "setting end rotation: " << _end << std::endl;
		}
    }
}
