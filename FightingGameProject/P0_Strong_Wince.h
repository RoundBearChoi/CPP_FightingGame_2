#pragma once
#include "PlayerState.h"

namespace RB::PlayerStates::Aku
{
	class P0_Strong_Wince : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Strong_Wince() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}