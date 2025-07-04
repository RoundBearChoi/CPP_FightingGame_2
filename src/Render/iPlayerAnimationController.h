#pragma once

#include "iAnimationObj.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Render
{
	#define GET_PLAYER_ANIMATION_CONTROLLER static_cast<Render::iPlayerAnimationController*>(Controllers::GetController(Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER))

	class iPlayerAnimationController : public Controllers::ControllerBase
	{
	public:
		virtual void DeleteAnimationObj(Players::PLAYER_TYPE playerID) = 0;
		virtual iAnimationObj* GetCurrentAnimationObj(Players::PLAYER_TYPE playerID, Sprites::SpriteType spriteType) = 0;
	};
}
