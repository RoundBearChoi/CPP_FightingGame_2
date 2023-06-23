#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "PlayerState.h"

#include "iPlayer.h"
#include "PlayerID.h"

#include "ActivePlayerStates.h"

#include "P0_FallDown.h"

namespace RB::PlayerStates
{
	class P0_JumpUp : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpUp() = default;
		~P0_JumpUp() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}