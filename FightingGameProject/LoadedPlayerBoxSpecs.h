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
		void Add(PlayerBoxSpecs specs);
		void SetSpriteType(RB::Sprites::SpriteEnum spriteType);
		RB::Sprites::SpriteEnum GetSpriteType();
		PlayerBoxSpecs* GetSpecs(RB::Sprites::SpriteEnum spriteType);

	private:
		std::vector<PlayerBoxSpecs> _vecSpecs;
		RB::Sprites::SpriteEnum _spriteType = RB::Sprites::SpriteEnum::NONE;
	};
}