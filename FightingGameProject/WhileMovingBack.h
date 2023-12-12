#pragma once
#include "StateComponentBase.h"
#include "MoveBackOnPress.h"
#include "MoveForwardOnPress.h"
#include "P0_Idle.h"
#include "P0_MoveForward.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingBack : public RB::States::StateComponentBase
	{
	public:
		WhileMovingBack(RB::States::iState* nextIdleState, RB::States::iState* nextWalkForwardState);
		~WhileMovingBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		MoveBackOnPress _moveBackOnPress;
		MoveForwardOnPress _moveForwardOnPress;
		bool _bMoveBack = false;
		bool _bMoveForward = false;
	};
}