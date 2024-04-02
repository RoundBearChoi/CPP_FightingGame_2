#pragma once

#include <string>

#include "SpriteType.h"

namespace RB::Updaters
{
	class SpriteTypeLoader
	{
	public:
		RB::Sprites::SpriteType LoadSpriteType(std::string _path);
	};
}