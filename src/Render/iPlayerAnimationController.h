#pragma once

#include "iAnimationObj.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Render
{
	#define GET_PLAYER_ANIMATION_CONTROLLER static_cast<RB::Render::iPlayerAnimationController*>(RB::Controllers::GetController(Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER))

	class iPlayerAnimationController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void DeleteAnimationObj(RB::Players::PlayerID playerID) = 0;
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType) = 0;
	};
}