#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/MoveUpOnJump.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/TransitionOnFixedUpdateCount.h"

#include "../Players/iSpecsController.h"

#include "F0_JumpUp_1.h"

namespace RB::Fighter_0_States
{
	class F0_JumpUp_0 : public Players::PlayerState
	{
	public:
		F0_JumpUp_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}