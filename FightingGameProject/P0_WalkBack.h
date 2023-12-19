#pragma once
#include "PlayerState.h"
#include "iPlayer.h"

#include "FixDirectionDuringState.h"
#include "TransitionToJumpUp.h"
#include "WhileMovingBack.h"

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