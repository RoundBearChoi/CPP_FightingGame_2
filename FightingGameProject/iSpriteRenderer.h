#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "PivotType.h"
#include "SpriteID.h"

namespace RB::Render
{
	class iSpriteRenderer
	{
	public:
		virtual ~iSpriteRenderer() {}

	public:
		virtual void Init() = 0;
		virtual void LoadSprite(std::string path, RB::Sprites::SpriteID spriteID) = 0;
		virtual void RenderSprite(RB::Sprites::SpriteID spriteID, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType) = 0;
	};
}