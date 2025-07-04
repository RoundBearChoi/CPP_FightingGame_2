#include "CustomRender.h"

namespace RB::Render
{
	float CustomRender::GetAmount()
	{
		float dif = _end - _start;

		float percentage = (float)_processedFrames / (float)(_totalFrames + 1); 

		// multiplier stays same when linear
		float multiplier = percentage;

		if (_operationType == Render::OperationType::SINE)
		{
			multiplier = RB::Ease::EaseInSine(percentage);
		}

		float result = dif * multiplier;

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
