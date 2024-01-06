#pragma once
#include <string>
#include "SpriteType.h"

namespace RB::Sprites
{
	class SpriteTypeString
	{
	public:
		SpriteTypeString(SpriteType spriteEnum, std::string string)
		{
			_spriteEnum = spriteEnum;
			_string = string;
		}

	public:
		SpriteType GetEnum() { return _spriteEnum; }
		const std::string& GetString() { return _string; }

	private:
		SpriteType _spriteEnum = SpriteType::NONE;
		std::string _string = "NONE";
	};
}