#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteID.h"

namespace RB::Sprites
{
	class LoadedSprite
	{
	public:
		LoadedSprite(std::string path, olc::Sprite* sprite, olc::Decal* decal, SpriteID spriteID);
		~LoadedSprite();

	public:
		std::string GetPath();
		olc::Sprite* GetSprite();
		olc::Decal* GetDecal();
		SpriteID GetSpriteID();

	private:
		std::string _path = "NONE";
		olc::Sprite* _sprite = nullptr;
		olc::Decal* _decal = nullptr;
		SpriteID _spriteID = SpriteID::NONE;
	};
}