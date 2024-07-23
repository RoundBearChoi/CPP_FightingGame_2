#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "PlayerStateComponents/MoveUpOnJump.h"
#include "PlayerStateComponents/MoveForwardOnJump_0.h"

#include "iSpecsController.h"

#include "P0_JumpForwardUp_1.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpForwardUp_0 : public RB::Players::PlayerState
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
