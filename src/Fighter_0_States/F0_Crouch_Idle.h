#pragma once

#include "../Players/PlayerState.h"

#include "../PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "../PlayerStateComponents/TransitionOnInput.h"
#include "../PlayerStateComponents/StandUpOnRelease.h"
#include "../PlayerStateComponents/MarkCrouchingOnEnter.h"
#include "../PlayerStateComponents/MarkCrouchingOnExit.h"

#include "F0_StandUp.h"
#include "F0_Crouch_Punch_Weak.h"

namespace RB::Fighter_0_States
{
	class F0_Crouch_Idle : public Players::PlayerState
	{
	public:
		F0_Crouch_Idle() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}