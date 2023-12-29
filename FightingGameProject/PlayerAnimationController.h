#pragma once

#include "Ani.h"
#include "JGetter.h"

#include "iPlayerController.h"
#include "iPlayerAnimationController.h"

#include "PlayerState.h"

namespace RB::Render
{
	class PlayerAnimationController : public iPlayerAnimationController
	{
	public:
		PlayerAnimationController() = default;
		~PlayerAnimationController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void DeleteAnimationObj(RB::Players::PlayerID playerID) override;
		iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum) override;

	private:
		void _SetFirstPlayerAnimations();
		void _SetNewPlayerAnimationObjOnChange(RB::Players::iPlayer& player);
		RB::Sprites::SpriteEnum _GetPlayerSpriteEnum(RB::Players::PlayerID playerID);
		void _SaveAnimationSpecs(std::string path, AnimationSpecs specs);
		AnimationSpecs _LoadAnimationSpecs(std::string path);

	private:
		AnimationLoader animationLoader;
	};
}