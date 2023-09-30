#pragma once
#include "StateComponentBase.h"
#include "MoveForward.h"
#include "P0_MoveForward.h"

#include "iPlayerController.h"
#include "iPlayer.h"

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
		MoveForward _moveForward;
	};
}