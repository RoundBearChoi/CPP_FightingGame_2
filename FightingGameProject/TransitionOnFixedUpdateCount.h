#pragma once
#include <cstdint>
#include "StateComponentBase.h"

#include "iPlayer.h"
#include "P0_Idle.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TransitionOnFixedUpdateCount : public RB::States::StateComponentBase
	{
	public:
		TransitionOnFixedUpdateCount(int32_t fixedUpdateOnCount, RB::States::iState* nextState);
		~TransitionOnFixedUpdateCount() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}