#pragma once

#include <string>
#include <vector>

#include "PlayerBoxSpecs.h"
#include "LoadedPlayerBoxData.h"

#include "../JParser.h"
#include "../Players/CharacterType.h"
#include "../Sprites/SpriteType.h"

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

		std::string GetPath(Sprites::SpriteType spriteType);
		void LoadSpecs(Sprites::SpriteType spriteType, Players::CharacterType characterType);
		LoadedPlayerBoxData* GetLoadedSpecs(Players::CharacterType characterType);
		void AddSpecs(PlayerBox box, Sprites::SpriteType spriteType, Players::CharacterType characterType);

	private:
		std::vector<LoadedPlayerBoxData> _vecLoadedSpecs;
	};
}