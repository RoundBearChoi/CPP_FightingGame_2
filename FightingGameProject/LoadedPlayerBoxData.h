#pragma once

#include <vector>

#include "PlayerBoxSpecs.h"
#include "CharacterType.h"

namespace RB::Collisions
{
	class LoadedPlayerBoxData
	{
	public:
		LoadedPlayerBoxData() = default;
		~LoadedPlayerBoxData() = default;

	public:
		void Add(PlayerBoxSpecs specs);
		void SetCharacterType(RB::Players::CharacterType characterType);
		RB::Players::CharacterType GetCharacterType();
		PlayerBoxSpecs* GetSpecs(RB::Sprites::SpriteEnum spriteType);
		PlayerBoxSpecs* GetSpecs(RB::Sprites::SpriteEnum spriteType, unsigned int frame);
		void EraseSpecs(RB::Sprites::SpriteEnum spriteType, unsigned int frame);
		void RefreshIterators();

	private:

		std::vector<PlayerBoxSpecs> _vecSpecs;
		RB::Players::CharacterType _characterType = RB::Players::CharacterType::NONE;
	};
}