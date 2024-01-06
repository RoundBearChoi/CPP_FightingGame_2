#pragma once
#include <vector>
#include "SpriteType.h"
#include "LoadedSprite.h"

namespace RB::Sprites
{
	class _SpriteLoader
	{
	public:
		_SpriteLoader() = default;
		~_SpriteLoader();

	public:
		LoadedSprite* LoadSprite(std::string path, SpriteType spriteEnum);
		LoadedSprite* GetLoadedSprite(SpriteType spriteEnum);

	private:
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}