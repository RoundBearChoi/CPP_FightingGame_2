#pragma once

#include "../Players/PlayerState.h"

#include "../PlayerStateComponents//MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/DetectHit.h"
#include "../PlayerStateComponents/TransitionOnAnimationEnd.h"

namespace RB::Fighter_0_States
{
	class F0_Crouch_Punch_Weak : public Players::PlayerState
	{
	public:
		F0_Crouch_Punch_Weak() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}