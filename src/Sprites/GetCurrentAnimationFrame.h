#pragma once

#include "GetCurrentSpriteType.h"
#include "SpriteType.h"

#include "../Players/PlayerID.h"

#include "../Render/iPlayerAnimationController.h"
#include "../Render/iAnimationObj.h"

namespace RB::Sprites
{
	extern int GetCurrentAnimationFrame(RB::Players::PlayerID id);
}