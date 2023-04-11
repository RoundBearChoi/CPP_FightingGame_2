#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteID.h"

namespace RB::Sprites
{
	class LoadedSprite
	{
	public:
		LoadedSprite(std::string path, olc::Sprite* sprite, SpriteID spriteID);
		~LoadedSprite();

	public:
		std::string GetPath();
		olc::Sprite* GetSprite();

	private:
		std::string _path = "NONE";
		olc::Sprite* _sprite = nullptr;
		SpriteID _spriteID = SpriteID::NONE;
	};
}