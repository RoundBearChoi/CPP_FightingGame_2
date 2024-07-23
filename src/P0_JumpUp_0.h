#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/MoveUpOnJump.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"

#include "Players/iSpecsController.h"

#include "P0_JumpUp_1.h"

namespace RB::Fighter_0_States
{
	class P0_JumpUp_0 : public RB::Players::PlayerState
	{
	public:
		P0_JumpUp_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
