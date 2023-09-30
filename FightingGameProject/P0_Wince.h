#pragma once
#include "PlayerState.h"
#include "ActivePlayerStates.h"

namespace RB::PlayerStates
{
	class P0_Wince : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Wince() = default;
		~P0_Wince() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}