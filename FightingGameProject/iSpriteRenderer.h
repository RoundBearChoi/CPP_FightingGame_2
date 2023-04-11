#pragma once
#include "olcPixelGameEngine.h"
#include "PivotType.h"

namespace RB::Render
{
	class iSpriteRenderer
	{
	public:
		virtual ~iSpriteRenderer() {}

	public:
		virtual void Init() = 0;
		virtual void RenderSprite(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType) = 0;
	};
}