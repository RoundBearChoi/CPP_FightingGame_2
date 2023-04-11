#pragma once
#include <iostream>
#include <filesystem>
#include "olcPixelGameEngine.h"

namespace RB::Sprites
{
	class SpriteLoader
	{
	public:
		SpriteLoader();
		~SpriteLoader();

	public:
		olc::Sprite* LoadSprite(std::string path);

	private:
		std::vector<olc::Sprite*> _loadedSprites;
	};
}