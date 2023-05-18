#pragma once
#include "StateComponentBase.h"
#include "MoveForwardDetector.h"
#include "P0_MoveForward.h"
#include "iPlayer.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

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
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		MoveForwardDetector _moveForwardDetector;
	};
}