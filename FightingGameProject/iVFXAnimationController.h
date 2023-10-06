#pragma once
#include "ControllerBase.h"

#include "SpriteEnum.h"

namespace RB::Render
{
	class iVFXAnimationController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void InstantiateAnimation(RB::Sprites::SpriteEnum spriteEnum) = 0;
	};

	extern iVFXAnimationController* VFX_ANIMATION_CONTROLLER;
}