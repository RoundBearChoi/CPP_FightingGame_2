#pragma once

#include <string>

#include "SpriteType.h"

#include "../JParser.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteType LoadSpriteType(const std::string& path);
}