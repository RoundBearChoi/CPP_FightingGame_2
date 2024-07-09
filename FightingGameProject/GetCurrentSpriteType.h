#pragma once
#include "SpriteType.h"
#include "PlayerID.h"

namespace RB::Sprites
{
	extern SpriteType GetCurrentSpriteType(RB::Players::PlayerID id);
}
