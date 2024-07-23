#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/MoveDownOnFall.h"
#include "PlayerStateComponents/MoveForwardOnJump_1.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpForwardUp_1 : public RB::Players::PlayerState
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
