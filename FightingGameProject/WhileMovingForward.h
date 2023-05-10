#pragma once
#include "StateComponentBase.h"
#include "MoveForwardDetector.h"
#include "MoveBackDetector.h"
#include "P0_Idle.h"
#include "P0_MoveBack.h"

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
		MoveForwardDetector _moveForwardDetector;
		MoveBackDetector _moveBackDetector;
		bool _keepMoving = false;
		bool _moveBack = false;
	};
}