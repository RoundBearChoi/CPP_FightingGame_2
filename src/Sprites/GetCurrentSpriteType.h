#pragma once

#include "SpriteType.h"

#include "../Players/PlayerType.h"
#include "../Players/PlayerState.h"

namespace RB::Sprites
{
	extern SpriteType GetCurrentSpriteType(RB::Players::PLAYER_TYPE id);
}
