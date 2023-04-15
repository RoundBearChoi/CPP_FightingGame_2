#pragma once
#include "StateComponentBase.h"
#include "GameplayControllers.h"

namespace RB::PlayerStateComponents
{
	class TriggerMoveForward : public RB::States::StateComponentBase
	{
	public:
		TriggerMoveForward();
		~TriggerMoveForward() override;
		
	public:
		void OnUpdate() override;

	private:
		bool _BothPressed();
		bool _MoveForwardPressed();

	private:
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
	};
}