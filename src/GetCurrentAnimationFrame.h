#pragma once

#include "PlayerID.h"
#include "SpriteType.h"
#include "GetCurrentSpriteType.h"

#include "iPlayerAnimationController.h"
#include "Render/iAnimationObj.h"

namespace RB::Sprites
{
	extern int GetCurrentAnimationFrame(RB::Players::PlayerID id);
}
