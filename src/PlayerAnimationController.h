#pragma once

#include <cassert>

#include "JParser.h"
#include "SpriteType.h"
#include "Render/AnimationObj.h"
#include "PlayerState.h"
#include "RenderLayerType.h"
#include "Render/AnimationContainer.h"

#include "Render/iAnimationObj.h"
#include "iPlayerAnimationController.h"
#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerAnimationController : public iPlayerAnimationController
	{
	public:
		PlayerAnimationController() = default;
		~PlayerAnimationController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void DeleteAnimationObj(RB::Players::PlayerID playerID) override;
		iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType) override;

	private:
		void _SetFirstPlayerAnimations();
		void _ChangePlayerAnimations();
		void _SetNewPlayerAnimationObjOnChange(RB::Players::iPlayer& player);
		RB::Sprites::SpriteType _GetPlayerSpriteType(RB::Players::PlayerID playerID);
		void _SaveAnimationSpecs(std::string path, AnimationSpecs specs);

	private:
		AnimationContainer _animationContainer;
	};
}
