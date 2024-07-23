#pragma once

#include "LoadedSprite.h"
#include "GetQuadOnPivot.h"
#include "PivotType.h"

#include "../enum.h"
#include "../Vector2.h"
#include "../SpriteType.h"
#include "../SpriteLoader.h"

#include "../Cam/iCamController.h"

namespace RB::Sprites
{
	class SpriteContainer
	{
	public:
		SpriteContainer() = default;
		~SpriteContainer();

	public:
		LoadedSprite* LoadSprite(std::string path, RB::Sprites::SpriteType spriteType);
		void RenderSprite(RB::Sprites::SpriteType spriteType, float width, float height, RB::Vector2 pos, olc::Pixel tint, RB::Sprites::PivotType pivotType, bool isWorldSpace);
		RB::Sprites::LoadedSprite* GetLoadedSprite(RB::Sprites::SpriteType spriteType);

	private:
		RB::Sprites::SpriteLoader _loader;
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}
