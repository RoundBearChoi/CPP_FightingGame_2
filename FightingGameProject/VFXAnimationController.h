#pragma once
#include "iVFXAnimationController.h"

#include "Ani.h"

namespace RB::Render
{
	class VFXAnimationController : public RB::Render::iVFXAnimationController
	{
	public:
		VFXAnimationController() = default;
		~VFXAnimationController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void InstantiateAnimation(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos) override;

	private:
		void _DeleteUsedAnimations();

	private:
		Ani _ani;
	};
}