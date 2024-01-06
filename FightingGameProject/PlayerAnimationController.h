#pragma once

#include "AnimationLoader.h"
#include "SpriteType.h"

#include "iPlayerAnimationController.h"
#include "iAnimationObj.h"

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
		iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteEnum) override;

	private:
		void _SetFirstPlayerAnimations();
		void _SetNewPlayerAnimationObjOnChange(RB::Players::iPlayer& player);
		RB::Sprites::SpriteType _GetPlayerSpriteEnum(RB::Players::PlayerID playerID);
		void _SaveAnimationSpecs(std::string path, AnimationSpecs specs);
		AnimationSpecs _LoadAnimationSpecs(std::string path);

	private:
		AnimationLoader _animationLoader;
	};
}