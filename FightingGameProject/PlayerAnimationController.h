#pragma once
#include "SpriteRenderer.h"
#include "AnimationLoader.h"

#include "iPlayerController.h"
#include "iPlayer.h"
#include "iPlayerAnimationController.h"

#include "iPlayerAnimationObj.h"
#include "PlayerAnimationObj.h"

#include "ActivePlayerStates.h"
#include "PlayerState.h"

namespace RB::Render
{
	class PlayerAnimationController : public iPlayerAnimationController
	{
	public:
		PlayerAnimationController();
		~PlayerAnimationController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void SetFirstAnimations();
		void SetNewAnimationObjsOnChange(RB::Players::iPlayer& player) override;
		RB::Sprites::SpriteEnum GetSpriteEnum(RB::Players::PlayerID playerID) override;
		void DeleteAnimationObj(RB::Players::PlayerID playerID) override;
		iPlayerAnimationObj* GetAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum) override;

	private:
		SpriteRenderer _spriteRenderer;
		AnimationLoader _animationLoader;
		std::vector<iPlayerAnimationObj*> _vecPlayerAnimationObjs;
	};
}