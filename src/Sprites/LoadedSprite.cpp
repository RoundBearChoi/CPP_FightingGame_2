#include "LoadedSprite.h"

namespace RB::Sprites
{
	LoadedSprite::LoadedSprite(std::string path, olc::Sprite* sprite, olc::Decal* decal, Sprites::SPRITE_TYPE spriteType)
	{
		_path = path;
		_sprite = sprite;
		_decal = decal;
		_spriteType = spriteType;
	}

	LoadedSprite::~LoadedSprite()
	{
		delete _sprite;
		delete _decal;
	}

	const std::string& LoadedSprite::GetPath() const
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

	Sprites::SPRITE_TYPE LoadedSprite::GetSpriteType()
	{
		return _spriteType;
	}

	olc::vi2d LoadedSprite::GetSpriteSize()
	{
		return olc::vi2d{ _sprite->width, _sprite->height };
	}
}
