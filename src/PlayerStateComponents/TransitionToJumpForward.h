#pragma once

#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"
#include "../iInputController.h"
#include "../States/iState.h"

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
