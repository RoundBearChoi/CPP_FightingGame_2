#pragma once

#include "AnimationLoader.h"
#include "SpriteType.h"
#include "AnimationContainer.h"

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
		iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType) override;

	private:
		void _SetFirstPlayerAnimations();
		void _SetNewPlayerAnimationObjOnChange(RB::Players::iPlayer& player);
		RB::Sprites::SpriteType _GetPlayerSpriteType(RB::Players::PlayerID playerID);
		void _SaveAnimationSpecs(std::string path, AnimationSpecs specs);
		AnimationSpecs _GetAnimationSpecs(std::string path);

	private:
		AnimationLoader _animationLoader;
		AnimationContainer _animationContainer;
	};
}
