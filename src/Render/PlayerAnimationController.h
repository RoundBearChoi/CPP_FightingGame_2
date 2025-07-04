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

		void DeleteAnimationObj(Players::PLAYER_TYPE playerID) override;
		iAnimationObj* GetCurrentAnimationObj(Players::PLAYER_TYPE playerID, Sprites::SPRITE_TYPE spriteType) override;

	private:
		void _SetFirstPlayerAnimations();
		void _ChangePlayerAnimations();
		void _SetNewPlayerAnimationObjOnChange(Players::iPlayer& player);
		Sprites::SPRITE_TYPE _GetPlayerSpriteType(Players::PLAYER_TYPE playerID);

	private:
		AnimationContainer _animationContainer;
	};
}
