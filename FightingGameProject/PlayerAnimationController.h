#pragma once
#include "iPlayerAnimationController.h"
#include "SpriteRenderer.h"
#include "AnimationLoader.h"
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

	public:
		RB::Sprites::SpriteID GetSpriteID(RB::Players::PlayerID playerID);
		void DeleteAnimationObj(RB::Players::PlayerID playerID);

	private:
		SpriteRenderer _spriteRenderer;
		AnimationLoader _animationLoader;
		std::vector<PlayerAnimationObj*> _vecPlayerAnimationObjs;
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}