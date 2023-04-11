#pragma once
#include "olcPixelGameEngine.h"
#include "PivotType.h"

namespace RB::Render
{
	class iBoxRenderer
	{
	public:
		virtual ~iBoxRenderer() {}

	public:
		virtual void Init() = 0;
		virtual void RenderSprite(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType) = 0;
	};
}