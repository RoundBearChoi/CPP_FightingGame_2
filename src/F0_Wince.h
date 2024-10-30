#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/FixWincingStatusDuringState.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "PlayerStateComponents/MoveHorizontalOnFixedUpdateCount.h"
#include "PlayerStateComponents/TransitionOnFixedUpdateCount.h"

#include "Fighter_0_States/F0_Idle.h"

namespace RB::Fighter_0_States
{
	class F0_Wince : public RB::Players::PlayerState
	{
	public:
		F0_Wince() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
