#pragma once

#include "iAnimationObj.h"

#include "../Controllers/ControllerBase.h"
#include "../Vector2.h"
#include "../Sprites/SpriteType.h"

namespace RB::Render
{
	#define GET_VFX_ANIMATION_CONTROLLER static_cast<Render::iVFXAnimationController*>(Controllers::GetController(Controllers::ControllerType::VFX_ANIMATION_CONTROLLER))

	class iVFXAnimationController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual iAnimationObj* InstantiateAnimation(RB::Sprites::SpriteType spriteType, RB::Vector2 pos, bool faceRight) = 0;
	};
}