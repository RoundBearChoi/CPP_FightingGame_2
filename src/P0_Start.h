#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/TransitionOnFixedUpdateCount.h"

#include "P0_Idle.h"

namespace RB::Fighter_0_States
{
	class P0_Start : public RB::Players::PlayerState
	{
	public:
		P0_Start() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
