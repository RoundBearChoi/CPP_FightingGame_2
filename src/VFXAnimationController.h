#pragma once

#include "Vector2.h"
#include "Render/AnimationObj.h"
#include "Render/AnimationContainer.h"

#include "Render/iVFXAnimationController.h"

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

		iAnimationObj* InstantiateAnimation(RB::Sprites::SpriteType spriteType, RB::Vector2 pos) override;

	private:
		void _DeleteFinishedAnimations();

	private:
		AnimationContainer _animationContainer;
	};
}
