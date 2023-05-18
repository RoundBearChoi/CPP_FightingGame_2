#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerState.h"

#include "ActivePlayerStates.h"

#include "TriggerJumpUp.h"
#include "TriggerMoveForward.h"
#include "TriggerMoveBack.h"

namespace RB::PlayerStates
{
	class P0_Idle : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Idle() = default;
		~P0_Idle() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}