#pragma once

#include "../States/StateComponentBase.h"
#include "../PlayerStateComponents/MoveForwardOnPress.h"

#include "../States/iState.h"
#include "../States/iStateMachine.h"
#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TransitionToWalkForward : public RB::States::StateComponentBase
	{
	public:
		TransitionToWalkForward(RB::States::iState* nextState);
		~TransitionToWalkForward() override {};
		
	public:
		void OnEnter() override;
		void OnUpdate() override;

	private:
		MoveForwardOnPress _moveForwardOnPress;
	};
}
