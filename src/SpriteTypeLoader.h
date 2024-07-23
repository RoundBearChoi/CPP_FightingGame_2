#pragma once

#include <string>

#include "JParser.h"
#include "Sprites/SpriteType.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteType LoadSpriteType(const std::string& path);
}
