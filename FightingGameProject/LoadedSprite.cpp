#include "LoadedSprite.h"

namespace RB::Sprites
{
	LoadedSprite::LoadedSprite(std::string path, olc::Sprite* sprite, SpriteType spriteType)
	{
		_path = path;
		_sprite = sprite;
		_spriteType = spriteType;

		std::cout << "loaded sprite: " << _path << std::endl;
	}

	LoadedSprite::~LoadedSprite()
	{
		std::cout << "destroying sprite: " << _path << std::endl;

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