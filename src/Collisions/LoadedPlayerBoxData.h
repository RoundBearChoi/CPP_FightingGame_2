#pragma once

#include <vector>

#include "PlayerBox.h"

#include "../PlayerBoxSpecs.h"
#include "../CharacterType.h"

namespace RB::Collisions
{
	class LoadedPlayerBoxData
	{
	public:
		LoadedPlayerBoxData(RB::Players::CharacterType characterType);
		LoadedPlayerBoxData(RB::Players::CharacterType characterType, PlayerBoxSpecs specs);
		~LoadedPlayerBoxData() = default;

	public:
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void Add(PlayerBoxSpecs specs);
		RB::Players::CharacterType GetCharacterType();
		PlayerBoxSpecs* GetSpecs(RB::Sprites::SpriteType spriteType);
		PlayerBox* GetSpecs(RB::Sprites::SpriteType spriteType, unsigned int frame);
		void EraseSpecs(RB::Sprites::SpriteType spriteType, unsigned int frame);
		void RefreshIterators();

	private:
		std::vector<PlayerBoxSpecs> _vecSpecs;
		RB::Players::CharacterType _characterType = RB::Players::CharacterType::NONE;
	};
}
