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
		//std::cout << "processing sizeChange.. " << std::to_string(_processedFrames) << std::endl;

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
