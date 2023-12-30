#pragma once

#include <vector>

#include "PlayerBoxSpecs.h"
#include "SpriteEnum.h"

namespace RB::Collisions
{
	class LoadedPlayerBoxSpecs
	{
	public:
		LoadedPlayerBoxSpecs() = default;
		~LoadedPlayerBoxSpecs() = default;

	public:
		RB::Sprites::SpriteEnum GetSpriteType();

	private:
		std::vector<PlayerBoxSpecs> _vecSpecs;
		RB::Sprites::SpriteEnum _spriteType = RB::Sprites::SpriteEnum::NONE;
	};
}