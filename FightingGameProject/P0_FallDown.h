#pragma once
#include <iostream>
#include "PlayerState.h"
#include "PlayerID.h"
#include "PlayerController.h"
#include "iPlayer.h"

#include "ActivePlayerStates.h"

#include "P0_Idle.h"

namespace RB::PlayerStates
{
	class P0_FallDown : public RB::PlayerStates::PlayerState
	{
	public:
		P0_FallDown() = default;
		~P0_FallDown() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}