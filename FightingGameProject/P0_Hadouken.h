#pragma once
#include "PlayerState.h"

#include "FixSpecialMoveStatusDuringState.h"
#include "MarkInitiallyFacingRight.h"
#include "TransitionOnAnimationEnd.h"

namespace RB::PlayerStates::Aku
{
	class P0_Hadouken : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Hadouken() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}