#pragma once
#include "PlayerState.h"
#include "iPlayer.h"

#include "ActivePlayerStates.h"

#include "TriggerJumpUp.h"
#include "WhileMovingForward.h"

namespace RB::PlayerStates
{
	class P0_MoveForward : public RB::PlayerStates::PlayerState
	{
	public:
		P0_MoveForward() = default;
		~P0_MoveForward() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}