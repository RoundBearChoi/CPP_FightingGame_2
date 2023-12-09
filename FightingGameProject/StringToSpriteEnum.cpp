#include "StringToSpriteEnum.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteEnum GetEnum(std::string str)
	{
		if (str._Equal("fighter_0_idle")) { return RB::Sprites::SpriteEnum::fighter_0_idle; }

		return RB::Sprites::SpriteEnum::NONE;
	}

	std::string GetString(RB::Sprites::SpriteEnum spriteEnum)
	{
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_idle) { return "\"fighter_0_idle\""; }

		return "NONE";
	}
}