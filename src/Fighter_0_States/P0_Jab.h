#pragma once

#include "../PlayerStateComponents/DetectHit.h"
#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/TransitionOnAnimationEnd.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	class P0_Jab : public RB::Players::PlayerState
	{
	public:
		P0_Jab() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
