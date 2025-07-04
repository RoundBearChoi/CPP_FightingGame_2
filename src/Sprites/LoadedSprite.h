#pragma once

#include "../olcPixelGameEngine.h"

#include "SpriteType.h"

namespace RB::Sprites
{
	class LoadedSprite
	{
	public:
		LoadedSprite(std::string path, olc::Sprite* sprite, olc::Decal* decal, Sprites::SPRITE_TYPE spriteType);
		~LoadedSprite();

	public:
		const std::string& GetPath() const;
		olc::Sprite* GetSprite();
		olc::Decal* GetDecal();
		Sprites::SPRITE_TYPE GetSpriteType();
		olc::vi2d GetSpriteSize();

	private:
		std::string _path = "NONE";
		olc::Sprite* _sprite = nullptr;
		olc::Decal* _decal = nullptr;
		Sprites::SPRITE_TYPE _spriteType = Sprites::SPRITE_TYPE::NONE;
	};
}
