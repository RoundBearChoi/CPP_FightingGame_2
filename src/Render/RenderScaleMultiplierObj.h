#pragma once

#include <iostream>
#include <string>

#include "CustomRender.h"
#include "OperationType.h"

namespace RB::Render
{
	class RenderScaleMultiplierObj : public CustomRender
	{
	public:
		RenderScaleMultiplierObj(int totalFrames, OperationType multiplierType, float totalMultiplier);

	public:
		void OnFixedUpdate() override;

	public:
		void SetStart(float start) override;

	private:
		OperationType _multiplierType = OperationType::NONE;
	};
}
