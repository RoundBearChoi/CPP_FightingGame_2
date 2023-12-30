#pragma once
#include "StateComponentBase.h"

#include "iState.h"

namespace RB::PlayerStateComponents
{
	class TransitionToJumpUp : public RB::States::StateComponentBase
	{
	public:
		TransitionToJumpUp(RB::States::iState* nextState);
		~TransitionToJumpUp() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
	};
}