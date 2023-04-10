#pragma once
#include "StateBase.h"

namespace RB::PlayerStates
{
	class PlayerIdle : public RB::States::StateBase
	{
	public:
		PlayerIdle();
		~PlayerIdle() override;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}