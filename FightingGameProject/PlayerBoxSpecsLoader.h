#pragma once

#include <string>
#include <vector>

#include "CharacterType.h"
#include "SpriteEnum.h"
#include "LoadedPlayerBoxData.h"
#include "PlayerBoxSpecs.h"

namespace RB::Collisions
{
	class PlayerBoxSpecsLoader
	{
	public:
		PlayerBoxSpecsLoader() = default;
		~PlayerBoxSpecsLoader() = default;

	public:
		void LoadSpecs(std::string path, RB::Sprites::SpriteEnum spriteType, RB::Players::CharacterType characterType);
		LoadedPlayerBoxData* GetLoadedSpecs(RB::Players::CharacterType characterType);
		PlayerBoxSpecs* AddSpecs(RB::Collisions::PlayerBoxSpecs specs);

	private:
		std::vector<LoadedPlayerBoxData> _vecLoadedSpecs;
	};
}