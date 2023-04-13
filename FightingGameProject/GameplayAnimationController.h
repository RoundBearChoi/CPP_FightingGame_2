#pragma once
#include "iGameplayAnimationController.h"
#include "SpriteRenderer.h"
#include "AnimationLoader.h"

namespace RB::Animations
{
	class GameplayAnimationController : public iGameplayAnimationController
	{
	public:
		GameplayAnimationController();
		~GameplayAnimationController();

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		RB::Render::SpriteRenderer _spriteRenderer;
		AnimationLoader _animationLoader;
	};
}