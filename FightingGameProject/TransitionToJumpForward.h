#pragma once
#include "StateComponentBase.h"

#include "iInputController.h"
#include "iPlayerController.h"

#include "P0_JumpForwardUp_0.h"

namespace RB::PlayerStateComponents
{
	class TransitionToJumpForward : public RB::States::StateComponentBase
	{
	public:
		TransitionToJumpForward(RB::States::iState* nextState);
		~TransitionToJumpForward() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
	};
}