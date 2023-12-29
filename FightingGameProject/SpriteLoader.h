#pragma once
#include <iostream>
#include <filesystem>
#include "olcPixelGameEngine.h"
#include "LoadedSprite.h"
#include "SpriteEnum.h"

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