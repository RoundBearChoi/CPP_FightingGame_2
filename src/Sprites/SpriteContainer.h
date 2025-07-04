#pragma once

#include "LoadedSprite.h"
#include "GetQuadOnPivot.h"
#include "PivotType.h"
#include "SpriteLoader.h"
#include "SpriteType.h"

#include "../enum.h"
#include "../Vector2.h"

#include "../Cam/iCamController.h"

namespace RB::Sprites
{
	class SpriteContainer
	{
	public:
		SpriteContainer() = default;
		~SpriteContainer();

	public:
		LoadedSprite* LoadSprite(std::string path, Sprites::SPRITE_TYPE spriteType);
		void RenderSprite(Sprites::SPRITE_TYPE spriteType, float width, float height, RB::Vector2 pos, olc::Pixel tint, Sprites::PivotType pivotType, bool isWorldSpace);
		Sprites::LoadedSprite* GetLoadedSprite(Sprites::SPRITE_TYPE spriteType);

	private:
		Sprites::SpriteLoader _loader;
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}
