#pragma once
#include "StateComponentBase.h"

#include "iInputController.h"
#include "iPlayerController.h"

#include "P0_JumpForward.h"

namespace RB::PlayerStateComponents
{
	class TriggerJumpForward : public RB::States::StateComponentBase
	{
	public:
		TriggerJumpForward() = default;
		~TriggerJumpForward() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
	};
}