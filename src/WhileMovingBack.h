#pragma once

#include "Vector2.h"
#include "StateComponentBase.h"
#include "PlayerStateComponents/MoveBackOnPress.h"
#include "MoveForwardOnPress.h"

#include "Players/iPlayerController.h"
#include "iState.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingBack : public RB::States::StateComponentBase
	{
	public:
		WhileMovingBack(float speed, RB::States::iState* nextIdleState, RB::States::iState* nextWalkForwardState);
		~WhileMovingBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		float _speed = 0;
		MoveBackOnPress _moveBackOnPress;
		MoveForwardOnPress _moveForwardOnPress;
		bool _bMoveBack = false;
		bool _bMoveForward = false;
	};
}
