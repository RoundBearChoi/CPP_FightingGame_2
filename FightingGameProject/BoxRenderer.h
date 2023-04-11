#pragma once
#include "olcPixelGameEngine.h"
#include "CurrentCam.h"
#include "iBoxRenderer.h"
#include "SpriteLoader.h"
#include "LoadedSprite.h"
#include "SpriteID.h"

namespace RB::Render
{
	class BoxRenderer : public iBoxRenderer
	{
	public:
		BoxRenderer();
		~BoxRenderer() override;

	public:
		void Init() override;

	public:
		void RenderBox(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType) override;

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}