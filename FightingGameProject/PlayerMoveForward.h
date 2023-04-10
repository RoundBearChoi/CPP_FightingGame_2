#pragma once
#include "StateBase.h"

namespace RB::PlayerStates
{
	class PlayerMoveForward : public RB::States::StateBase
	{
	public:
		PlayerMoveForward();
		~PlayerMoveForward() override;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}