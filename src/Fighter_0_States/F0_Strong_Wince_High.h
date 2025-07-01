#pragma once

#include "../Players/PlayerState.h"

#include "../PlayerStateComponents/SetWincingStatusOnEnter.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/MoveHorizontalOnFixedUpdateCount.h"
#include "../PlayerStateComponents/TransitionOnFixedUpdateCount.h"

#include "F0_Idle.h"
#include "F0_Kneel.h"

namespace RB::Fighter_0_States
{
	class F0_Strong_Wince_High : public Players::PlayerState
	{
	public:
		F0_Strong_Wince_High();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
