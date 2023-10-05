#pragma once
#include "ControllerBase.h"
#include "iAnimationObj.h"

namespace RB::Render
{
	class iPlayerAnimationController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void DeleteAnimationObj(RB::Players::PlayerID playerID) = 0;
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum) = 0;
	};

	extern iPlayerAnimationController* PLAYER_ANIMATION_CONTROLLER;
}