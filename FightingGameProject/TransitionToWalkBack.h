#pragma once
#include "StateComponentBase.h"

#include "MoveBackOnPress.h"

#include "iState.h"

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