#pragma once
#include "iGameplayAnimationController.h"
#include "iSpriteRenderer.h"
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
		RB::Render::iSpriteRenderer* _spriteRenderer = nullptr;
		AnimationLoader _animationLoader;
	};
}