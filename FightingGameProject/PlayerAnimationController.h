#pragma once
#include "SpriteObj.h"
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

		RB::Sprites::SpriteEnum GetSpriteEnum(RB::Players::PlayerID playerID) override;
		void DeleteAnimationObj(RB::Players::PlayerID playerID) override;
		iAnimationObj* GetAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum) override;

	private:
		void _SetFirstAnimations();
		void _SetNewAnimationObjsOnChange(RB::Players::iPlayer& player);

	private:
		SpriteObj _spriteObj;
		AnimationLoader _animationLoader;
		std::vector<iAnimationObj*> _vecPlayerAnimationObjs;
	};
}