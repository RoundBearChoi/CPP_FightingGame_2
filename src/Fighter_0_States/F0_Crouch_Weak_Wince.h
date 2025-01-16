#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/FixWincingStatusDuringState.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/MoveHorizontalOnFixedUpdateCount.h"
#include "../PlayerStateComponents/TransitionOnFixedUpdateCount.h"

#include "F0_Idle.h"
#include "F0_Crouch_Idle.h"
#include "F0_Kneel.h"

namespace RB::Fighter_0_States
{
	class F0_Crouch_Weak_Wince : public RB::Players::PlayerState
	{
	public:
		F0_Crouch_Weak_Wince() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}