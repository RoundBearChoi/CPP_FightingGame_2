#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/DetectHit.h"
#include "PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "TransitionOnAnimationEnd.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	class P0_Strong_Punch : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Strong_Punch() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
