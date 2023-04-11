#pragma once
#include "olcPixelGameEngine.h"
#include "CurrentCam.h"
#include "iBoxRenderer.h"
#include "SpriteLoader.h"
#include "LoadedSprite.h"
#include "SpriteID.h"

namespace RB::Render
{
	class SpriteRenderer : public iBoxRenderer
	{
	public:
		SpriteRenderer();
		~SpriteRenderer() override;

	public:
		void Init() override;

	public:
		void RenderSprite(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType) override;

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}