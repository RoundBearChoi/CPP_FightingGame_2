#pragma once
#include "StateComponentBase.h"

#include "P0_Idle.h"

namespace RB::PlayerStateComponents
{
	class TriggerIdleOnAnimationEnd : public RB::States::StateComponentBase
	{
	public:
		TriggerIdleOnAnimationEnd() = default;
		~TriggerIdleOnAnimationEnd() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;
	};
}