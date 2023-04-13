#pragma once
#include "iPlayerAnimationController.h"
#include "SpriteRenderer.h"
#include "AnimationRenderer.h"
#include "PlayerAnimationObj.h"
#include "ControllerGroup.h"
#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::Render
{
	class PlayerAnimationController : public iPlayerAnimationController
	{
	public:
		PlayerAnimationController();
		~PlayerAnimationController();

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		SpriteRenderer _spriteRenderer;
		AnimationRenderer _animationRenderer;
		std::vector<PlayerAnimationObj*> _vecPlayerAnimationObjs;
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}