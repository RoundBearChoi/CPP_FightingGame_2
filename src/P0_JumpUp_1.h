#pragma once

#include "PlayerState.h"
#include "MarkInitiallyFacingRight.h"
#include "MoveDownOnFall.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpUp_1 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpUp_1() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
