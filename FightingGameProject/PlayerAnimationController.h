#pragma once
#include "SpriteRenderer.h"
#include "AnimationLoader.h"
#include "PlayerAnimationObj.h"
#include "ControllerBase.h"
#include "iPlayer.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

#include "ActivePlayerStates.h"
#include "PlayerState.h"

namespace RB::Render
{
	class PlayerAnimationController : public RB::Controllers::ControllerBase
	{
	public:
		PlayerAnimationController();
		~PlayerAnimationController() override;
		static inline PlayerAnimationController* PTR = nullptr;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void SetFirstAnimations();
		void SetNewAnimationObjsOnChange(RB::Players::iPlayer& player);
		RB::Sprites::SpriteEnum GetSpriteEnum(RB::Players::PlayerID playerID);
		void DeleteAnimationObj(RB::Players::PlayerID playerID);
		PlayerAnimationObj* GetAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum);

	private:
		SpriteRenderer _spriteRenderer;
		AnimationLoader _animationLoader;
		std::vector<PlayerAnimationObj*> _vecPlayerAnimationObjs;
	};
}