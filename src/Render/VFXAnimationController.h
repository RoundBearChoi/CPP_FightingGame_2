#pragma once

#include <iostream>

#include "AnimationObj.h"
#include "AnimationContainer.h"

#include "iVFXAnimationController.h"

#include "../Vector2.h"

namespace RB::Render
{
	class VFXAnimationController : public Render::iVFXAnimationController
	{
	public:
		VFXAnimationController() = default;
		~VFXAnimationController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		iAnimationObj* InstantiateAnimation(Sprites::SpriteType spriteType, RB::Vector2 pos, bool faceRight) override;

	private:
		void _DeleteFinishedAnimations();

	private:
		AnimationContainer _animationContainer;
	};
}
