#pragma once
#include "MoveSpecs.h"
#include "PlayerState.h"
#include "iPlayer.h"

#include "FixDirectionDuringState.h"
#include "TransitionToJumpForward.h"
#include "TransitionToJumpUp.h"
#include "WhileMovingForward.h"

#include "iSpecsController.h"

namespace RB::PlayerStates::Aku
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