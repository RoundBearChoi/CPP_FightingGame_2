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
		void SetStart(float start) override;
		
	public:
		float GetRenderScaleMultiplier();
		
	private:
		RenderScaleMultiplierType _multiplierType = RenderScaleMultiplierType::NONE;
		//float _totalMultiplier = 1.0f;
	};
}
