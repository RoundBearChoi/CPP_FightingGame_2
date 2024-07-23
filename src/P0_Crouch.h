#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "PlayerStateComponents/TransitionOnAnimationEnd.h"

#include "Fighter_0_States/P0_Crouch_Idle.h"

namespace RB::Fighter_0_States
{
	class P0_Crouch : public RB::Players::PlayerState
	{
	public:
		P0_Crouch() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
