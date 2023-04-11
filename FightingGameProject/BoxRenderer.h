#pragma once
#include "olcPixelGameEngine.h"
#include "GameplayControllers.h"
#include "SpriteLoader.h"
#include "LoadedSprite.h"
#include "SpriteID.h"
#include "PivotType.h"

namespace RB::Render
{
	class BoxRenderer
	{
	public:
		BoxRenderer();
		~BoxRenderer();

	public:
		void Init();

	public:
		void RenderBox(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType);

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}