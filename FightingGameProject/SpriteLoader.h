#pragma once
#include <iostream>
#include <filesystem>
#include "olcPixelGameEngine.h"
#include "LoadedSprite.h"
#include "SpriteType.h"

namespace RB::Sprites
{
	class SpriteLoader
	{
	public:
		SpriteLoader();
		~SpriteLoader();

	public:
		LoadedSprite* LoadSprite(std::string path, SpriteType spriteType);

	private:
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}