#include "RenderScaleMultiplierObj.h"

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
		
	}

	void RenderScaleMultiplierObj::SetStart(float start)
	{
		if (_processedFrames == 0)
		{
			_start = start;

			std::cout << std::endl;
			std::cout << "setting start render scale: " << start  << std::endl;

			_end = start * _totalMultiplier;

			std::cout << "setting end render scale: " << _end << std::endl;
		}
	}

	float RenderScaleMultiplierObj::GetRenderScaleMultiplier()
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

			if (_totalMultiplier < 1.0f)
			{
				//result = 1.0f - result;
			}

			//std::cout << "processed frame " << _processedFrames << " multiplier: "  << _start + result << std::endl;

			return _start + result;
		}

		// temp
		return 1.0f;
	}
}
