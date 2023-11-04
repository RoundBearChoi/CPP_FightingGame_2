#pragma once
#include "PlayerState.h"

#include "ActivePlayerStates.h"

#include "MoveDownOnFall.h"

namespace RB::PlayerStates
{
	class P0_JumpForwardUp_1 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpForwardUp_1() = default;
		~P0_JumpForwardUp_1() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}