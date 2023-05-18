#pragma once
#include "StateComponentBase.h"
#include "MoveBackDetector.h"
#include "P0_MoveBack.h"
#include "iPlayer.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

namespace RB::PlayerStateComponents
{
	class TriggerMoveBack : public RB::States::StateComponentBase
	{
	public:
		TriggerMoveBack() = default;
		~TriggerMoveBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;

	private:
		MoveBackDetector _moveBackDetector;
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
	};
}