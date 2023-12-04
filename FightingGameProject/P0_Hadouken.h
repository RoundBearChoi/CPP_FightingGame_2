#pragma once
#include "PlayerState.h"
//#include "ActivePlayerStates.h"

#include "TriggerIdleOnAnimationEnd.h"

namespace RB::PlayerStates
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