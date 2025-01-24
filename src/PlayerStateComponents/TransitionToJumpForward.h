#pragma once

#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"
#include "../Input/iInputController.h"
#include "../States/iState.h"

namespace RB::PlayerStateComponents
{
	class TransitionToJumpForward : public RB::States::StateComponentBase
	{
	public:
		TransitionToJumpForward(RB::States::iState* nextState, bool reverse);
		~TransitionToJumpForward() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;

	private:
		bool _reverse = false;
	};
}