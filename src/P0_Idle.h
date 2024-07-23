#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "PlayerStateComponents/TransitionToJumpForward.h"
#include "TransitionToJumpUp.h"
#include "PlayerStateComponents/TransitionOnInput.h"
#include "TransitionToWalkForward.h"
#include "TransitionToWalkBack.h"

#include "P0_Jab.h"
#include "P0_Strong_Punch.h"
#include "P0_Strong_Kick.h"
#include "P0_JumpForwardUp_0.h"
#include "P0_JumpUp_0.h"
#include "P0_WalkForward.h"
#include "P0_WalkBack.h"
#include "P0_Crouch.h"

namespace RB::PlayerStates::Aku
{
	class P0_Idle : public RB::Players::PlayerState
	{
	public:
		P0_Idle() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
