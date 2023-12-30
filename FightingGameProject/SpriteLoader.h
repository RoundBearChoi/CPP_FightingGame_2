#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteEnum.h"
#include "LoadedSprite.h"
#include "PivotType.h"

#include "_SpriteLoader.h"

namespace RB::Sprites
{
	class SpriteLoader
	{
	public:
		SpriteLoader() = default;
		~SpriteLoader() = default;

	public:
		void LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum);
		void RenderSprite(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType, bool useWorldSpace = true);
		RB::Sprites::LoadedSprite* GetLoadedSprite(RB::Sprites::SpriteEnum spriteEnum);

	private:
		RB::Sprites::_SpriteLoader _loader;
	};
}