#include "CustomRender.h"

namespace RB::Render
{
	float CustomRender::GetAmount()
	{
		float dif = _end - _start;

        float perFrame = 0.0f;

        if (_totalFrames <= 0)
        {
            perFrame = dif;
        }
        else
        {
            perFrame = dif / float(_totalFrames + 1);
        }

        float result = perFrame * _processedFrames;

        return _start + result;
	}

    void CustomRender::AddProcessedFrame()
    {
        _processedFrames++;
    }
    
    bool CustomRender::DoDelete()
	{
		if (_processedFrames >= _totalFrames + 1)
		{
			//std::cout << "deleting.." << std::endl;
			
			return true;
		}
		else
		{
			return false;
		}
	}

	int CustomRender::GetProcessedFrameCount()
	{
		return _processedFrames;
	}
}
