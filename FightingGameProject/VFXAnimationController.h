#pragma once
#include "iVFXAnimationController.h"

#include "AnimationLoader.h"

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

		void InstantiateAnimation(RB::Sprites::SpriteType spriteType, olc::vf2d pos) override;

	private:
		void _DeleteFinishedAnimations();

	private:
		AnimationLoader _animationLoader;
	};
}