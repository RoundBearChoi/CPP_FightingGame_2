#pragma once
#include <iostream>
#include <filesystem>
#include "olcPixelGameEngine.h"
#include "LoadedSprite.h"

namespace RB::Sprites
{
	class SpriteLoader
	{
	public:
		SpriteLoader();
		~SpriteLoader();

	public:
		LoadedSprite* LoadSprite(std::string path);

	private:
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}