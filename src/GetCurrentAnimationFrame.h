#pragma once

#include "PlayerID.h"
#include "SpriteType.h"
#include "GetCurrentSpriteType.h"

#include "iPlayerAnimationController.h"
#include "iAnimationObj.h"

namespace RB::Sprites
{
	extern int GetCurrentAnimationFrame(RB::Players::PlayerID id);
}
