#pragma once

#include "PlayerState.h"
#include "MoveDownOnFall.h"
#include "MoveForwardOnJump_1.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpForwardUp_1 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpForwardUp_1() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
