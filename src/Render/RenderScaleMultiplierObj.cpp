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
		if (_start == 0.0f && _end == 0.0f)
		{
			_start = _lastRenderScale;
			_end = _lastRenderScale * _totalMultiplier;
		}

		_processedFrames++;
	}

	void RenderScaleMultiplierObj::SetLastRenderScale(float lastRenderScale)
	{
		_lastRenderScale = lastRenderScale;
	}

	float RenderScaleMultiplierObj::GetRenderScaleMultiplier()
	{
		if (_multiplierType == RenderScaleMultiplierType::LINEAR)
		{
			float oneFrame = _totalMultiplier / _totalFrames;

			float result = oneFrame * _processedFrames + 1;

			return result;
		}

		// temp
		return 1.0f;
	}
}
