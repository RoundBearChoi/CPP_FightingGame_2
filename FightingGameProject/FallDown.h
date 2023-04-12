#pragma once
#include "StateBase.h"

namespace RB::PlayerStates
{
	class FallDown : public RB::States::StateBase
	{
	public:
		FallDown();
		~FallDown() override;
	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}