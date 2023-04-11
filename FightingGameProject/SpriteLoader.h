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
		void LoadSprite(std::string path);
	};
}