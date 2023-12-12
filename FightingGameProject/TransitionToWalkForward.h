#pragma once
#include "StateComponentBase.h"
#include "MoveForwardOnPress.h"
#include "P0_WalkForward.h"

#include "iPlayerController.h"
#include "iPlayer.h"

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