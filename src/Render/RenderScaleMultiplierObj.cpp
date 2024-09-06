#include "RenderScaleMultiplierObj.h"

namespace RB::Render
{
	RenderScaleMultiplierObj::RenderScaleMultiplierObj(int totalFrames, OperationType operationType, float totalMultiplier)
	{
		_totalFrames = totalFrames;
		_operationType = operationType;
		_totalAmount = totalMultiplier;
	}

	void RenderScaleMultiplierObj::OnFixedUpdate()
	{
		
	}

	void RenderScaleMultiplierObj::SetStart(float start)
	{
		if (_processedFrames == 0)
		{
			_start = start;
	
			//std::cout << std::endl;
			//std::cout << "setting start render scale: " << start  << std::endl;
	
			_end = start * _totalAmount;
	
			//std::cout << "setting end render scale: " << _end << std::endl;
		}
	}
}
