#include "CustomRenderBase.h"

namespace RB::Render
{
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
}
