#pragma once
#include "olcPixelGameEngine.h"
#include "enum.h"
#include "SpriteType.h"
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
		LoadedSprite* LoadSprite(std::string path, RB::Sprites::SpriteType spriteType);
		void RenderSprite(RB::Sprites::SpriteType spriteType, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType, bool useWorldSpace = true);
		RB::Sprites::LoadedSprite* GetLoadedSprite(RB::Sprites::SpriteType spriteType);

	private:
		RB::Sprites::_SpriteLoader _loader;
	};
}