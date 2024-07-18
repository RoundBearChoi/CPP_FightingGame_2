#pragma once

#include "PlayerState.h"
#include "MarkInitiallyFacingRight.h"
#include "TransitionOnAnimationEnd.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	class P0_StandUp : public RB::PlayerStates::PlayerState
	{
	public:
		P0_StandUp() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
