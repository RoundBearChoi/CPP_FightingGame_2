#include "StringToCharacterTypeEnum.h"

namespace RB::Players
{
	RB::Players::CharacterType GetEnum(std::string str)
	{
		if (str._Equal("AKU")) { return RB::Players::CharacterType::AKU; }

		return RB::Players::CharacterType();
	}

	std::string GetString(RB::Players::CharacterType characterType)
	{
		if (characterType == RB::Players::CharacterType::AKU) { return "\"AKU\""; }

		return std::string();
	}
}