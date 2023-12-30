#pragma once
#include "StateComponentBase.h"

#include "MoveBackOnPress.h"
#include "MoveForwardOnPress.h"

#include "iState.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingBack : public RB::States::StateComponentBase
	{
	public:
		WhileMovingBack(int speed, RB::States::iState* nextIdleState, RB::States::iState* nextWalkForwardState);
		~WhileMovingBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		int _speed = 0;
		MoveBackOnPress _moveBackOnPress;
		MoveForwardOnPress _moveForwardOnPress;
		bool _bMoveBack = false;
		bool _bMoveForward = false;
	};
}