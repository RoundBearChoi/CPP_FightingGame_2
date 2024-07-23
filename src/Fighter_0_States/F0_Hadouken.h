#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/FixSpecialMoveStatusDuringState.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/TransitionOnAnimationEnd.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	class F0_Hadouken : public RB::Players::PlayerState
	{
	public:
		F0_Hadouken() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
