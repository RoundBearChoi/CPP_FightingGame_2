#pragma once
#include <string>
#include "SpriteEnum.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteEnum GetEnum(std::string str);
	std::string GetString(RB::Sprites::SpriteEnum spriteEnum);
}