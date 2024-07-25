#include "CustomRenderBase.h"

namespace RB::Render
{
    void CustomRenderBase::AddProcessedFrame()
    {
        _processedFrames++;
    }
    
    bool CustomRenderBase::DoDelete()
	{
		if (_processedFrames >= _totalFrames)
		{
			//std::cout << "deleting.." << std::endl;
			
			return true;
		}
		else
		{
			return false;
		}
	}

	int CustomRenderBase::GetProcessedFrameCount()
	{
		return _processedFrames;
	}
}
