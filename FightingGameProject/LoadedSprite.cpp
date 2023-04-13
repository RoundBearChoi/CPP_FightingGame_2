#include "LoadedSprite.h"

namespace RB::Sprites
{
	LoadedSprite::LoadedSprite(std::string path, olc::Sprite* sprite, olc::Decal* decal, SpriteID spriteID)
	{
		_path = path;
		_sprite = sprite;
		_decal = decal;
		_spriteID = spriteID;

		std::cout << "loaded sprite & decal: " << _path << " (spriteID " << static_cast<int>(_spriteID) << ")" << std::endl;
	}

	LoadedSprite::~LoadedSprite()
	{
		std::cout << "destroying sprite & decal: " << _path << " (spriteID " << static_cast<int>(_spriteID) << ")" << std::endl;

		delete _sprite;
		delete _decal;
	}

	std::string LoadedSprite::GetPath()
	{
		return _path;
	}

	olc::Sprite* LoadedSprite::GetSprite()
	{
		return _sprite;
	}

	olc::Decal* LoadedSprite::GetDecal()
	{
		return _decal;
	}

	SpriteID LoadedSprite::GetSpriteID()
	{
		return _spriteID;
	}

	olc::vi2d LoadedSprite::GetSpriteSize()
	{
		return olc::vi2d{ _sprite->width, _sprite->height };
	}
}