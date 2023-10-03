#pragma once
#include <cstdint>
#include "StateComponentBase.h"

#include "iPlayer.h"
#include "P0_Idle.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TriggerIdleOnFixedUpdateCount : public RB::States::StateComponentBase
	{
	public:
		TriggerIdleOnFixedUpdateCount(int32_t fixedUpdateOnCount);
		~TriggerIdleOnFixedUpdateCount() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}