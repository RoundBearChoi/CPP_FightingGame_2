#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerT.h"

#include "SpriteType.h"

namespace RB::Render
{
	class iVFXAnimationController : public RB::Controllers::ControllerT<iVFXAnimationController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void InstantiateAnimation(RB::Sprites::SpriteType spriteType, olc::vf2d pos) = 0;
	};
}