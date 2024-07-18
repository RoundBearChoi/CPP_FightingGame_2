#pragma once

#include <string>

#include "JParser.h"
#include "SpriteType.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteType LoadSpriteType(const std::string& path);
}
