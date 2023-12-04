#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerT.h"

#include "SpriteEnum.h"

namespace RB::Render
{
	class iVFXAnimationController : public RB::Controllers::ControllerT<iVFXAnimationController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void InstantiateAnimation(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos) = 0;
	};
}