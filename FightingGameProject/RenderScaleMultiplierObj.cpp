#include "RenderScaleMultiplierObj.h"

#include <iostream>
#include <string>

namespace RB::Render
{
	RenderScaleMultiplierObj::RenderScaleMultiplierObj(int totalFrames, RenderScaleMultiplierType multiplierType, float totalMultiplier)
	{
		_totalFrames = totalFrames;
		_multiplierType = multiplierType;
		_totalMultiplier = totalMultiplier;
	}

	void RenderScaleMultiplierObj::OnFixedUpdate()
	{
		//std::cout << "processing sizeChange.. " << std::to_string(_processedFrames) << std::endl;

		_processedFrames++;
	}

	bool RenderScaleMultiplierObj::DoDelete()
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

	float RenderScaleMultiplierObj::GetRenderScaleMultiplier()
	{
		// temp
		return 3.0f;
	}
}
