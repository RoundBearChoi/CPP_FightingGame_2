#include "LoadedSprite.h"

namespace RB::Sprites
{
	LoadedSprite::LoadedSprite(std::string path, olc::Sprite* sprite, SpriteID spriteID)
	{
		_path = path;
		_sprite = sprite;
		_spriteID = spriteID;

		std::cout << "loaded sprite: " << _path << " (sprite type " << static_cast<int>(_spriteID) << ")" << std::endl;
	}

	LoadedSprite::~LoadedSprite()
	{
		std::cout << "destroying sprite: " << _path << " (sprite type " << static_cast<int>(_spriteID) << ")" << std::endl;

		delete _sprite;
	}

	std::string LoadedSprite::GetPath()
	{
		return _path;
	}

	olc::Sprite* LoadedSprite::GetSprite()
	{
		return _sprite;
	}
}