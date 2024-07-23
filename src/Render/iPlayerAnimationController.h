#pragma once

#include "iAnimationObj.h"

#include "../Controllers/ControllerT.h"

namespace RB::Render
{
	class iPlayerAnimationController : public RB::Controllers::ControllerT<iPlayerAnimationController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void DeleteAnimationObj(RB::Players::PlayerID playerID) = 0;
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType) = 0;
	};
}
