#pragma once
#include <iostream>

#include "iPlayerController.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "PlayerState.h"

#include "MoveDownOnFall.h"

namespace RB::PlayerStates
{
	class P0_JumpUp_1 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpUp_1() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}