#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerState.h"

#include "FixDirectionDuringState.h"
#include "TriggerJumpForward.h"
#include "TransitionToJumpUp.h"
#include "TriggerJab.h"
#include "TransitionToWalkForward.h"
#include "TransitionToWalkBack.h"

namespace RB::PlayerStates
{
	class P0_Idle : public RB::PlayerStates::PlayerState
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