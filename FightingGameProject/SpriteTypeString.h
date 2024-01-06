#pragma once
#include <string>
#include "SpriteType.h"

namespace RB::Sprites
{
	class SpriteTypeString
	{
	public:
		SpriteTypeString(SpriteType spriteType, std::string string)
		{
			_spriteType = spriteType;
			_string = string;
		}

	public:
		SpriteType GetEnum() { return _spriteType; }
		const std::string& GetString() { return _string; }

	private:
		SpriteType _spriteType = SpriteType::NONE;
		std::string _string = "NONE";
	};
}