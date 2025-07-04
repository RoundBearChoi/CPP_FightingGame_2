#pragma once

#include <string>

#include "SpriteType.h"

#include "../JParser.h"

namespace RB::Sprites
{
	Sprites::SPRITE_TYPE LoadSpriteType(const std::string& path);
}
