#include "LoadedSprite.h"

namespace RB::Sprites
{
	LoadedSprite::LoadedSprite(std::string path, olc::Sprite* sprite, olc::Decal* decal, SpriteEnum spriteEnum)
	{
		_path = path;
		_sprite = sprite;
		_decal = decal;
		_spriteEnum = spriteEnum;

		std::cout << "loaded sprite & decal: " << _path << " (spriteEnum " << static_cast<int>(_spriteEnum) << ")" << std::endl;
	}

	LoadedSprite::~LoadedSprite()
	{
		std::cout << "destroying sprite & decal: " << _path << " (spriteEnum " << static_cast<int>(_spriteEnum) << ")" << std::endl;

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

	SpriteEnum LoadedSprite::GetSpriteEnum()
	{
		return _spriteEnum;
	}

	olc::vi2d LoadedSprite::GetSpriteSize()
	{
		return olc::vi2d{ _sprite->width, _sprite->height };
	}
}