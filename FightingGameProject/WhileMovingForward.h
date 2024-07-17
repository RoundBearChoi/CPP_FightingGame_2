#pragma once
#include "StateComponentBase.h"

#include "MoveForwardOnPress.h"
#include "MoveBackOnPress.h"

#include "iState.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingForward : public RB::States::StateComponentBase
	{
	public:
		WhileMovingForward(float speed, RB::States::iState* nextIdleState, RB::States::iState* nextWalkBackState);
		~WhileMovingForward() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		float _speed = 0;
		MoveForwardOnPress _moveForwardOnPress;
		MoveBackOnPress _moveBackOnPress;
		bool _bMoveForward = false;
		bool _bMoveBack = false;
	};
}
