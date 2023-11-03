#pragma once
#include "StateComponentBase.h"

#include "iInputController.h"
#include "iPlayerController.h"

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