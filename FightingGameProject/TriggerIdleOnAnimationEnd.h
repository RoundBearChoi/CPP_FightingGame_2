#pragma once
#include "StateComponentBase.h"

#include "P0_Idle.h"

#include "iPlayerController.h"
#include "iPlayerAnimationController.h"

namespace RB::PlayerStateComponents
{
	class TriggerIdleOnAnimationEnd : public RB::States::StateComponentBase
	{
	public:
		TriggerIdleOnAnimationEnd(RB::States::iState* nextState);
		~TriggerIdleOnAnimationEnd() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;
	};
}