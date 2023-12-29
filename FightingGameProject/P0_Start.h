#pragma once
#include "PlayerState.h"

namespace RB::PlayerStates::Aku
{
	class P0_Start : public RB::PlayerStates::PlayerState
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