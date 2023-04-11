#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iController.h"
#include "iBoxRenderer.h"

namespace RB::Render
{
	class iBoxRenderController : public RB::Controllers::iController
	{
	public:
		virtual ~iBoxRenderController() {}

	public:
		//virtual void RenderBox(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType) = 0;
		virtual iBoxRenderer* GetBoxRenderer() = 0;
	};
}