#pragma once
#include "StateComponentBase.h"
#include "MoveForwardOnPress.h"
#include "MoveBackOnPress.h"
#include "P0_Idle.h"
#include "P0_MoveBack.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingForward : public RB::States::StateComponentBase
	{
	public:
		WhileMovingForward() = default;
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