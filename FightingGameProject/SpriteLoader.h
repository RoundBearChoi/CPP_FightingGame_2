#pragma once
#include <iostream>
#include <filesystem>
#include "olcPixelGameEngine.h"
#include "LoadedSprite.h"
#include "SpriteID.h"

namespace RB::Sprites
{
	class SpriteLoader
	{
	public:
		SpriteLoader() = default;
		~SpriteLoader();

	public:
		LoadedSprite* LoadSprite(std::string path, SpriteID spriteID);
		LoadedSprite* GetLoadedSprite(SpriteID spriteID);

	private:
		std::vector<LoadedSprite*> _vecLoadedSprites;
	};
}