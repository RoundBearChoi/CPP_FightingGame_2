#pragma once

#include "iAnimationObj.h"

#include "../Controllers/ControllerT.h"
#include "../Vector2.h"
#include "../Sprites/SpriteType.h"

namespace RB::Render
{
	class iVFXAnimationController : public RB::Controllers::ControllerT<iVFXAnimationController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual iAnimationObj* InstantiateAnimation(RB::Sprites::SpriteType spriteType, RB::Vector2 pos, bool faceRight) = 0;
	};
}
