#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/SetWincingStatusOnEnter.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/MoveHorizontalOnFixedUpdateCount.h"
#include "../PlayerStateComponents/TransitionOnFixedUpdateCount.h"
#include "../PlayerStateComponents/TransitionOnDeath.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	class F0_Weak_Wince_Mid : public Players::PlayerState
	{
	public:
		F0_Weak_Wince_Mid();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
