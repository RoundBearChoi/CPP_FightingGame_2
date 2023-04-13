#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "CurrentCam.h"
#include "SpriteLoader.h"
#include "SpriteID.h"
#include "LoadedSprite.h"
#include "PivotType.h"

namespace RB::Render
{
	class SpriteRenderer
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

	public:
		void Init();

	public:
		void LoadSprite(std::string path, RB::Sprites::SpriteID spriteID);
		void RenderSprite(RB::Sprites::SpriteID spriteID, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType);
		RB::Sprites::LoadedSprite* GetLoadedSprite(RB::Sprites::SpriteID spriteID);

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}