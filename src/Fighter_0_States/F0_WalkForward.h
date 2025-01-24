#pragma once

#include "../Players/PlayerState.h"
#include "../Players/iSpecsController.h"

#include "../PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "../PlayerStateComponents/TransitionToJumpForward.h"
#include "../PlayerStateComponents/TransitionToJumpUp.h"
#include "../PlayerStateComponents/WhileMovingForward.h"

#include "F0_JumpForward_0.h"
#include "F0_JumpUp_0.h"
#include "F0_Idle.h"
#include "F0_WalkBack.h"

namespace RB::Fighter_0_States
{
	class F0_WalkForward : public RB::Players::PlayerState
	{
	public:
		F0_WalkForward() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}