#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "PlayerStateComponents/MoveDownOnFall.h"

#include "Fighter_0_States/P0_Idle.h"

namespace RB::Fighter_0_States
{
	class P0_JumpUp_1 : public RB::Players::PlayerState
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
