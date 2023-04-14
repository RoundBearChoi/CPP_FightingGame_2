#pragma once
#include "StateComponentBase.h"

namespace RB::PlayerStateComponents
{
	class TriggerMoveForward : public RB::States::StateComponentBase
	{
	public:
		TriggerMoveForward();
		
	public:
		void OnUpdate() override;
	};
}