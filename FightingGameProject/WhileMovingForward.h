#pragma once
#include "StateComponentBase.h"
#include "MoveForwardOnPress.h"
#include "MoveBackOnPress.h"
#include "P0_Idle.h"
#include "P0_WalkBack.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingForward : public RB::States::StateComponentBase
	{
	public:
		WhileMovingForward(RB::States::iState* nextIdleState, RB::States::iState* nextWalkBackState);
		~WhileMovingForward() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		MoveForwardOnPress _moveForwardOnPress;
		MoveBackOnPress _moveBackOnPress;
		bool _bMoveForward = false;
		bool _bMoveBack = false;
	};
}