#pragma once

#include <string>

#include "SpriteType.h"

#include "../JParser.h"

namespace RB::Sprites
{
	Sprites::SpriteType LoadSpriteType(const std::string& path);
}
