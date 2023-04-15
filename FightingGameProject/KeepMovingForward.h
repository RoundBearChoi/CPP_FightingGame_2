#pragma once
#include "StateComponentBase.h"
#include "MoveForwardDetector.h"
#include "MoveBackDetector.h"
#include "Idle.h"

namespace RB::PlayerStateComponents
{
	class KeepMovingForward : public RB::States::StateComponentBase
	{
	public:
		KeepMovingForward();
		~KeepMovingForward() override;

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