#pragma once
#include "PlayerState.h"
#include "iPlayer.h"

#include "FixDirectionDuringState.h"
#include "TriggerJumpUp.h"
#include "WhileMovingBack.h"

namespace RB::PlayerStates
{
	class P0_MoveBack : public RB::PlayerStates::PlayerState
	{
	public:
		P0_MoveBack() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}