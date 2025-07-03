#pragma once

#include <cassert>

#include "AnimationObj.h"
#include "AnimationContainer.h"
#include "RenderLayerType.h"

#include "iAnimationObj.h"
#include "iPlayerAnimationController.h"

#include "../JParser.h"
#include "../Sprites/SpriteType.h"
#include "../Players/PlayerState.h"

#include "../Players/iPlayerController.h"

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

		void DeleteAnimationObj(Players::PlayerID playerID) override;
		iAnimationObj* GetCurrentAnimationObj(Players::PlayerID playerID, Sprites::SpriteType spriteType) override;

	private:
		void _SetFirstPlayerAnimations();
		void _ChangePlayerAnimations();
		void _SetNewPlayerAnimationObjOnChange(Players::iPlayer& player);
		Sprites::SpriteType _GetPlayerSpriteType(Players::PlayerID playerID);

	private:
		AnimationContainer _animationContainer;
	};
}
