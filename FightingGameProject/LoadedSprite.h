#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteType.h"

namespace RB::Sprites
{
	class LoadedSprite
	{
	public:
		LoadedSprite(std::string path, olc::Sprite* sprite, SpriteType spriteType);
		~LoadedSprite();

	public:
		std::string GetPath();
		olc::Sprite* GetSprite();

	private:
		std::string _path = "NONE";
		olc::Sprite* _sprite = nullptr;
		SpriteType _spriteType = SpriteType::NONE;
	};
}