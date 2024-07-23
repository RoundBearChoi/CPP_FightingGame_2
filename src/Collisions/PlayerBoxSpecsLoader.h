#pragma once

#include <string>
#include <vector>

#include "PlayerBoxSpecs.h"
#include "LoadedPlayerBoxData.h"

#include "../JParser.h"
#include "../Players/CharacterType.h"
#include "../SpriteType.h"

namespace RB::Collisions
{
	class PlayerBoxSpecsLoader
	{
	public:
		PlayerBoxSpecsLoader() = default;
		~PlayerBoxSpecsLoader() = default;

	public:
		void OnUpdate();
		void OnFixedUpdate();

		std::string GetPath(RB::Sprites::SpriteType spriteType);
		void LoadSpecs(RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType);
		LoadedPlayerBoxData* GetLoadedSpecs(RB::Players::CharacterType characterType);
		void AddSpecs(PlayerBox box, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType);

	private:
		std::vector<LoadedPlayerBoxData> _vecLoadedSpecs;
	};
}
