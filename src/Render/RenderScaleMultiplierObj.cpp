#include "RenderScaleMultiplierObj.h"

namespace RB::Render
{
	RenderScaleMultiplierObj::RenderScaleMultiplierObj(int totalFrames, RenderScaleMultiplierType multiplierType, float totalMultiplier)
	{
		_totalFrames = totalFrames;
		_multiplierType = multiplierType;
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

	float RenderScaleMultiplierObj::GetAmount()
	{
		if (_processedFrames == 0)
		{
			return 1.0f;
		}

		// assuming linear for now
		if (_multiplierType == RenderScaleMultiplierType::LINEAR)
		{
			float dif = _end - _start;

			float perFrame = dif / float(_totalFrames);

			float result = perFrame * float(_processedFrames + 1);

			return _start + result;
		}

		// temp
		return 1.0f;
	}
}
