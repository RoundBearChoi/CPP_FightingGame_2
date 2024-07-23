#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "../PlayerStateComponents/TransitionToJumpForward.h"
#include "../PlayerStateComponents/TransitionToJumpUp.h"
#include "../PlayerStateComponents/TransitionOnInput.h"
#include "../PlayerStateComponents/TransitionToWalkForward.h"
#include "../PlayerStateComponents/TransitionToWalkBack.h"

#include "F0_Jab.h"
#include "P0_Strong_Punch.h"
#include "F0_Strong_Kick.h"
#include "F0_JumpUp_0.h"
#include "P0_WalkForward.h"
#include "P0_WalkBack.h"
#include "F0_JumpForwardUp_0.h"
#include "F0_Crouch.h"

namespace RB::Fighter_0_States
{
	class F0_Idle : public RB::Players::PlayerState
	{
	public:
		F0_Idle() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
