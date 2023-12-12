#pragma once
#include "PlayerState.h"
#include "iPlayer.h"

#include "FixDirectionDuringState.h"
#include "TransitionToJumpForward.h"
#include "TransitionToJumpUp.h"
#include "WhileMovingForward.h"

namespace RB::PlayerStates
{
	class P0_WalkForward : public RB::PlayerStates::PlayerState
	{
	public:
		P0_WalkForward() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}