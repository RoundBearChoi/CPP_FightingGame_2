#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "LoadedSprite.h"

namespace RB::Sprites
{
	class _SpriteLoader
	{
	public:
		_SpriteLoader() = default;
		~_SpriteLoader();

	public:
		LoadedSprite* LoadSprite(std::string path, SpriteEnum spriteEnum);
		LoadedSprite* GetLoadedSprite(SpriteEnum spriteEnum);

	private:
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}