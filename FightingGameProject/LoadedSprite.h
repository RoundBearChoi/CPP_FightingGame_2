#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteType.h"

namespace RB::Sprites
{
	class LoadedSprite
	{
	public:
		LoadedSprite(std::string path, olc::Sprite* sprite, olc::Decal* decal, SpriteType spriteEnum);
		~LoadedSprite();

	public:
		const std::string& GetPath() const;
		olc::Sprite* GetSprite();
		olc::Decal* GetDecal();
		SpriteType GetSpriteEnum();
		olc::vi2d GetSpriteSize();

	private:
		std::string _path = "NONE";
		olc::Sprite* _sprite = nullptr;
		olc::Decal* _decal = nullptr;
		SpriteType _spriteEnum = SpriteType::NONE;
	};
}