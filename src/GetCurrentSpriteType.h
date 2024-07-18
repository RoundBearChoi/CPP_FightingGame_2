#pragma once

#include "SpriteType.h"
#include "PlayerID.h"
#include "PlayerState.h"

namespace RB::Sprites
{
	extern SpriteType GetCurrentSpriteType(RB::Players::PlayerID id);
}
