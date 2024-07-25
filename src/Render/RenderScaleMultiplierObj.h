#pragma once

#include <iostream>
#include <string>

#include "CustomRenderBase.h"
#include "RenderScaleMultiplierType.h"
//#include "iAnimationObj.h"

namespace RB::Render
{
	//class iAnimationObj; // forward declare

	class RenderScaleMultiplierObj : public CustomRenderBase
	{
	public:
		RenderScaleMultiplierObj(int totalFrames, RenderScaleMultiplierType multiplierType, float totalMultiplier);

		void OnFixedUpdate() override;
		void SetLastRenderScale(float lastRenderScale);
		
	public:
		bool DoDelete();
		float GetRenderScaleMultiplier();
		
	private:
		RenderScaleMultiplierType _multiplierType = RenderScaleMultiplierType::NONE;
		float _lastRenderScale = 1.0f;
		float _totalMultiplier = 1.0f;
	};
}
