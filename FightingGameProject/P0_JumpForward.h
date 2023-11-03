#pragma once
#include "PlayerState.h"

#include "ActivePlayerStates.h"

namespace RB::PlayerStates
{
	class P0_JumpForward : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpForward() = default;
		~P0_JumpForward() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}