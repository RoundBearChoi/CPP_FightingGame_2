#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"

#include "PlayerState.h"
#include "iPlayer.h"
#include "PlayerID.h"

#include "MarkInitiallyFacingRight.h"
#include "MoveUpOnJump.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpUp_0 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpUp_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}