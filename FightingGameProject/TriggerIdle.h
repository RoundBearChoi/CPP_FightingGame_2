#pragma once
#include <cstdint>
#include "StateComponentBase.h"

#include "iPlayer.h"
#include "P0_Idle.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TriggerIdle : public RB::States::StateComponentBase
	{
	public:
		TriggerIdle(int32_t fixedUpdateOnCount);
		~TriggerIdle() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}