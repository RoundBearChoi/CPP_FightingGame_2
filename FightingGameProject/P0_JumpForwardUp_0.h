#pragma once
#include "PlayerState.h"

#include "ActivePlayerStates.h"

namespace RB::PlayerStates
{
	class P0_JumpForwardUp_0 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpForwardUp_0() = default;
		~P0_JumpForwardUp_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}