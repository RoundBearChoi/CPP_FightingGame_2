#pragma once
#include <iostream>

#include "iPlayerController.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "PlayerState.h"

//#include "P0_Idle.h"
#include "MoveDownOnFall.h"

#include "ActivePlayerStates.h"

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