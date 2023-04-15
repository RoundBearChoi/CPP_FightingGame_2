#pragma once
#include "StateComponentBase.h"
#include "MoveBackDetector.h"
#include "MoveBack.h"

namespace RB::PlayerStateComponents
{
	class TriggerMoveBack : public RB::States::StateComponentBase
	{
	public:
		TriggerMoveBack();
		~TriggerMoveBack() override;

	public:
		void OnEnter() override;
		void OnUpdate() override;

	private:
		MoveBackDetector _moveBackDetector;
	};
}