#pragma once
#include "MoveSpecs.h"
#include "PlayerState.h"
#include "iPlayer.h"

#include "DoNotFixDirectionDuringState.h"
#include "TransitionToJumpUp.h"
#include "WhileMovingBack.h"

#include "iSpecsController.h"

namespace RB::PlayerStates::Aku
{
	class P0_WalkBack : public RB::PlayerStates::PlayerState
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