#pragma once

#include "../Players/PlayerState.h"

#include "../PlayerStateComponents//MarkInitiallyFacingRight.h"
//#include "../PlayerStateComponents/DoNotFixDirectionDuringState.h"

namespace RB::Fighter_0_States
{
	class F0_Crouch_Punch_Weak : public RB::Players::PlayerState
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
