#pragma once
#include "iGameplayAnimationController.h"
#include "SpriteRenderer.h"
#include "AnimationRenderer.h"

namespace RB::Render
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
		SpriteRenderer _spriteRenderer;
		AnimationRenderer _animationRenderer;
	};
}