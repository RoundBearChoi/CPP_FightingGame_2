#pragma once

#include "../SpriteType.h"
#include "../Players/PlayerID.h"
#include "../Players/PlayerState.h"

namespace RB::Sprites
{
	extern SpriteType GetCurrentSpriteType(RB::Players::PlayerID id);
}
