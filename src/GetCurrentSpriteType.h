#pragma once

#include "SpriteType.h"
#include "Players/PlayerID.h"
#include "PlayerState.h"

namespace RB::Sprites
{
	extern SpriteType GetCurrentSpriteType(RB::Players::PlayerID id);
}
