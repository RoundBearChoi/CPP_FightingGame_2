#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/DetectHit.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/TransitionOnAnimationEnd.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	class F0_Strong_Kick : public Players::PlayerState
	{
	public:
		F0_Strong_Kick();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
