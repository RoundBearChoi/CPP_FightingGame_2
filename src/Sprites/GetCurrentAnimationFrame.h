#pragma once

#include "GetCurrentSpriteType.h"
#include "SpriteType.h"

#include "../Players/PlayerType.h"

#include "../Render/iPlayerAnimationController.h"
#include "../Render/iAnimationObj.h"

namespace RB::Sprites
{
	extern int GetCurrentAnimationFrame(Players::PLAYER_TYPE id);
}
