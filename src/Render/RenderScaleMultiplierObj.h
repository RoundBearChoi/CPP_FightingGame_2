#pragma once

#include <iostream>
#include <string>

#include "CustomRenderBase.h"
#include "RenderScaleMultiplierType.h"

namespace RB::Render
{
	//class iAnimationObj; // forward declare

	class RenderScaleMultiplierObj : public CustomRenderBase
	{
	public:
		RenderScaleMultiplierObj(int totalFrames, RenderScaleMultiplierType multiplierType, float totalMultiplier);

	public:
		void OnFixedUpdate() override;

	public:
		void SetStart(float start) override;
		float GetAmount() override;

	private:
		RenderScaleMultiplierType _multiplierType = RenderScaleMultiplierType::NONE;
	};
}
