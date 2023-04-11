#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "CurrentCam.h"
#include "iSpriteRenderer.h"
#include "SpriteLoader.h"
#include "LoadedSprite.h"
#include "SpriteID.h"

namespace RB::Render
{
	class SpriteRenderer : public iSpriteRenderer
	{
	public:
		SpriteRenderer();
		~SpriteRenderer() override;

	public:
		void Init() override;

	public:
		void LoadSprite(std::string path, RB::Sprites::SpriteID spriteID) override;
		void RenderSprite(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType) override;

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}