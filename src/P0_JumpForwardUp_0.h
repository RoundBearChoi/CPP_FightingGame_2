#pragma once

#include "PlayerState.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "MoveUpOnJump.h"
#include "MoveForwardOnJump_0.h"

#include "iSpecsController.h"

#include "P0_JumpForwardUp_1.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpForwardUp_0 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpForwardUp_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
