#pragma once
#include "StateComponentBase.h"
#include "MoveForwardDetector.h"
#include "P0_MoveForward.h"

namespace RB::PlayerStateComponents
{
	class TriggerMoveForward : public RB::States::StateComponentBase
	{
	public:
		TriggerMoveForward() = default;
		~TriggerMoveForward() override {};
		
	public:
		void OnEnter() override;
		void OnUpdate() override;

	private:
		MoveForwardDetector _moveForwardDetector;
	};
}