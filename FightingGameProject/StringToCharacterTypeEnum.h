#pragma once

#include <string>

#include "CharacterType.h"

namespace RB::Players
{
	RB::Players::CharacterType GetEnum(std::string str);
	std::string GetString(RB::Players::CharacterType characterType);
}