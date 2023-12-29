#pragma once
#include "PlayerState.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpUp_0 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpUp_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}