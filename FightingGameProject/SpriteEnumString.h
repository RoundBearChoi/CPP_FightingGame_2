#pragma once
#include <iostream>
#include "SpriteEnum.h"

namespace RB::Sprites
{
	class SpriteEnumString
	{
	public:
		SpriteEnumString(SpriteEnum spriteEnum, std::string string)
		{
			_spriteEnum = spriteEnum;
			_string = string;
		}

	public:
		SpriteEnum GetEnum() { return _spriteEnum; }
		const std::string* GetString() { return &_string; }

	private:
		SpriteEnum _spriteEnum = SpriteEnum::NONE;
		std::string _string = "NONE";
	};
}