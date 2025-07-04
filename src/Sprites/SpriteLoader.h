#pragma once

#include <vector>
#include <filesystem>

#include "LoadedSprite.h"
#include "SpriteType.h"

namespace RB::Sprites
{
	class SpriteLoader
	{
	public:
		SpriteLoader() = default;
		~SpriteLoader();

	public:
		LoadedSprite* LoadSprite(std::string path, Sprites::SPRITE_TYPE spriteType);
	};
}
