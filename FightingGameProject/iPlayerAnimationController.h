#pragma once
#include "ControllerBase.h"
#include "iPlayerAnimationObj.h"

namespace RB::Render
{
	class iPlayerAnimationController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void SetFirstAnimations() = 0;
		virtual void SetNewAnimationObjsOnChange(RB::Players::iPlayer& player) = 0;
		virtual RB::Sprites::SpriteEnum GetSpriteEnum(RB::Players::PlayerID playerID) = 0;
		virtual void DeleteAnimationObj(RB::Players::PlayerID playerID) = 0;
		virtual iPlayerAnimationObj* GetAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum) = 0;
	};

	extern iPlayerAnimationController* PLAYER_ANIMATION_CONTROLLER;
}