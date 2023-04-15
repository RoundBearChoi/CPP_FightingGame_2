#pragma once
#include "StateComponentBase.h"
#include "MoveForwardDetector.h"

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

	private:
		MoveForwardDetector _moveForwardDetector;
	};
}