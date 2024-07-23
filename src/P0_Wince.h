#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/FixWincingStatusDuringState.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "PlayerStateComponents/MoveHorizontalOnFixedUpdateCount.h"
#include "PlayerStateComponents/TransitionOnFixedUpdateCount.h"

#include "Fighter_0_States/P0_Idle.h"

namespace RB::Fighter_0_States
{
	class P0_Wince : public RB::Players::PlayerState
	{
	public:
		P0_Wince() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
