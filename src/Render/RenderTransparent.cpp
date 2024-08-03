#include "RenderTransparent.h"

namespace RB::Render
{
    RenderTransparent::RenderTransparent(int totalFrames, float totalRotation)
    {
        _totalFrames = totalFrames;
        _totalAmount = totalRotation;
    }

    void RenderTransparent::OnFixedUpdate()
    {
        
    }

    void RenderTransparent::SetStart(float start)
    {
		if (_processedFrames == 0)
		{
			_start = start;
	
			std::cout << std::endl;
			std::cout << "setting start transparency: " << start  << std::endl;
	
			_end = start * _totalAmount;
	
			std::cout << "setting end transparency: " << _end << std::endl;
		}
    }

    float RenderTransparent::GetAmount()
    {
		if (_processedFrames == 0)
		{
			return 1.0f;
		}

        float dif = _end - _start;

        float perFrame = dif / float(_totalFrames);

        float result = perFrame * float(_processedFrames + 1);

        return _start + result;
    }
}
