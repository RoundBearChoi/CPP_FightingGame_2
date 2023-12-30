#pragma once

#include <string>
#include <vector>

#include "CharacterType.h"
#include "SpriteEnum.h"
#include "LoadedPlayerBoxSpecs.h"

namespace RB::Collisions
{
	class PlayerBoxSpecsLoader
	{
	public:
		PlayerBoxSpecsLoader() = default;
		~PlayerBoxSpecsLoader() = default;

	public:
		void LoadSpecs(std::string path, RB::Sprites::SpriteEnum spriteType, RB::Players::CharacterType characterType);
		LoadedPlayerBoxSpecs* GetLoadedSpecs(RB::Players::CharacterType characterType);

	private:
		std::vector<LoadedPlayerBoxSpecs> _vecLoadedSpecs;
	};
}