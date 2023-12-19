#pragma once
#include "PlayerState.h"

#include "FixWincingStatusDuringState.h"
#include "MoveHorizontalOnFixedUpdateCount.h"
#include "TransitionOnFixedUpdateCount.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	class P0_Wince : public RB::PlayerStates::PlayerState
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