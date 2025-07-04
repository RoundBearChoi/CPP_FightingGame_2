#pragma once

#include "SpriteType.h"

#include "../Players/PlayerType.h"
#include "../Players/PlayerState.h"

namespace RB::Sprites
{
	extern Sprites::SPRITE_TYPE GetCurrentSpriteType(Players::PLAYER_TYPE id);
}
