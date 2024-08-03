#include "CustomRender.h"

namespace RB::Render
{
    void CustomRender::AddProcessedFrame()
    {
        _processedFrames++;
    }
    
    bool CustomRender::DoDelete()
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

	int CustomRender::GetProcessedFrameCount()
	{
		return _processedFrames;
	}
}
