#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteEnum.h"

namespace RB::Sprites
{
	class LoadedSprite
	{
	public:
		LoadedSprite(std::string path, olc::Sprite* sprite, olc::Decal* decal, SpriteEnum spriteEnum);
		~LoadedSprite();

	public:
		std::string GetPath();
		olc::Sprite* GetSprite();
		olc::Decal* GetDecal();
		SpriteEnum GetSpriteEnum();
		olc::vi2d GetSpriteSize();

	private:
		std::string _path = "NONE";
		olc::Sprite* _sprite = nullptr;
		olc::Decal* _decal = nullptr;
		SpriteEnum _spriteEnum = SpriteEnum::NONE;
	};
}