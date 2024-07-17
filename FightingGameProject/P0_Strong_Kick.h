#pragma once

#include "PlayerState.h"
#include "DetectHit.h"
#include "MarkInitiallyFacingRight.h"
#include "TransitionOnAnimationEnd.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	class P0_Strong_Kick : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Strong_Kick() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
