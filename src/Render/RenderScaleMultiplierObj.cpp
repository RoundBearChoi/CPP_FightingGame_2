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
		if (_processedFrames == 0)
		{
			std::cout << "setting start" << std::endl;
			_start = _lastRenderScale;
			//_end = _lastRenderScale * _totalMultiplier;
		}
	}

	void RenderScaleMultiplierObj::SetLastRenderScale(float lastRenderScale)
	{
		_lastRenderScale = lastRenderScale;
	}

	float RenderScaleMultiplierObj::GetRenderScaleMultiplier()
	{
		if (_multiplierType == RenderScaleMultiplierType::LINEAR)
		{
			float perFrame = _totalMultiplier / float(_totalFrames);

			float result = (perFrame * (float)(_processedFrames + 1)) + 1.0f;

			std::cout << "start * result: " << _start * result << std::endl;

			return _start * result;
		}

		// temp
		return 1.0f;
	}
}
