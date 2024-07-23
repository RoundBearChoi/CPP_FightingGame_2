#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "../PlayerStateComponents/StandUpOnRelease.h"

#include "../P0_StandUp.h"

namespace RB::Fighter_0_States
{
	class P0_Crouch_Idle : public RB::Players::PlayerState
	{
	public:
		P0_Crouch_Idle() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
