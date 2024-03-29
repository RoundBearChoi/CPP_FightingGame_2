#pragma once

#include <string>
#include <vector>

#include "CharacterType.h"
#include "SpriteType.h"
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
		void OnUpdate();
		void OnFixedUpdate();

		void LoadSpecs(std::string path, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType);
		LoadedPlayerBoxData* GetLoadedSpecs(RB::Players::CharacterType characterType);
		void AddSpecs(PlayerBox box, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType);

	private:
		std::vector<LoadedPlayerBoxData> _vecLoadedSpecs;
	};
}