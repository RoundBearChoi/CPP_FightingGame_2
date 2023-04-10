#pragma once
#include "StateBase.h"

namespace RB::PlayerStates
{
	class Idle : public RB::States::StateBase
	{
	public:
		Idle();
		~Idle() override;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}