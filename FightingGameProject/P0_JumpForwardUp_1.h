#pragma once
#include "PlayerState.h"

#include "MoveDownOnFall.h"
#include "MoveForwardOnJump_1.h"

namespace RB::PlayerStates
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