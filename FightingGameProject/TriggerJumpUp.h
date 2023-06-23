#pragma once
#include "StateComponentBase.h"
#include "P0_JumpUp.h"
#include "iPlayer.h"

#include "PlayerController.h"
#include "InputController.h"

namespace RB::PlayerStateComponents
{
	class TriggerJumpUp : public RB::States::StateComponentBase
	{
	public:
		TriggerJumpUp() = default;
		~TriggerJumpUp() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
	};
}