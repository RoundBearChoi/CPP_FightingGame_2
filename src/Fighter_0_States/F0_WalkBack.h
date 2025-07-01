#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "../PlayerStateComponents/TransitionToJumpUp.h"
#include "../PlayerStateComponents/WhileMovingBack.h"

#include "../Players/iSpecsController.h"

#include "F0_JumpBack_0.h"
#include "F0_JumpUp_0.h"
#include "F0_Idle.h"
#include "F0_WalkForward.h"

namespace RB::Fighter_0_States
{
	class F0_WalkBack : public RB::Players::PlayerState
	{
	public:
		F0_WalkBack();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
