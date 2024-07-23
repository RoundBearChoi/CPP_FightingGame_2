#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "../PlayerStateComponents/TransitionToJumpUp.h"
#include "../PlayerStateComponents/WhileMovingBack.h"

#include "../Players/iSpecsController.h"

#include "F0_JumpUp_0.h"
#include "F0_Idle.h"
#include "P0_WalkForward.h"

namespace RB::Fighter_0_States
{
	class P0_WalkBack : public RB::Players::PlayerState
	{
	public:
		P0_WalkBack() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
