#pragma once

#include <iostream>
#include <string>

#include "CustomRender.h"

namespace RB::Render
{
	class RenderScaleMultiplierObj : public CustomRender
	{
	public:
		RenderScaleMultiplierObj(int totalFrames, OperationType operationType, float totalMultiplier);

	public:
		void OnFixedUpdate() override;

	public:
		void SetStart(float start) override;
	};
}
