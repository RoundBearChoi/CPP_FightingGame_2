#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"

namespace RB::Sprites
{
	class LoadedSprite
	{
	public:
		LoadedSprite(std::string path, olc::Sprite* sprite);
		~LoadedSprite();

	public:
		std::string GetPath();
		olc::Sprite* GetSprite();

	private:
		std::string _path = "NONE";
		olc::Sprite* _sprite = nullptr;
	};
}