#pragma once

#include "../States/StateComponentBase.h"
#include "../PlayerStateComponents/MoveBackOnPress.h"

#include "../States/iState.h"
#include "../States/iStateMachine.h"
#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TransitionToWalkBack : public RB::States::StateComponentBase
	{
	public:
		TransitionToWalkBack(RB::States::iState* nextState);
		~TransitionToWalkBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;

	private:
		MoveBackOnPress _moveBackOnPress;
	};
}
