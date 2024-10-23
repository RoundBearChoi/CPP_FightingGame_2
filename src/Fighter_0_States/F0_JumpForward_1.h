#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/MoveDownOnFall.h"
#include "../PlayerStateComponents/MoveForwardOnJump_0.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	class F0_JumpForward_1 : public RB::Players::PlayerState
	{
	public:
		F0_JumpForward_1() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
