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
		LoadedSprite* LoadSprite(std::string path, Sprites::SpriteType spriteType);
		void RenderSprite(Sprites::SpriteType spriteType, float width, float height, RB::Vector2 pos, olc::Pixel tint, Sprites::PivotType pivotType, bool isWorldSpace);
		Sprites::LoadedSprite* GetLoadedSprite(Sprites::SpriteType spriteType);

	private:
		Sprites::SpriteLoader _loader;
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}
