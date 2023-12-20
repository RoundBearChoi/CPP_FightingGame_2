#include "StringToCharacterTypeEnum.h"

namespace RB::Players
{
	RB::Players::CharacterType GetEnum(std::string str)
	{
		if (str._Equal("PLAYER_0")) { return RB::Players::CharacterType::PLAYER_0; }

		return RB::Players::CharacterType();
	}

	std::string GetString(RB::Players::CharacterType characterType)
	{
		if (characterType == RB::Players::CharacterType::PLAYER_0) { return "\"PLAYER_0\""; }

		return std::string();
	}
}