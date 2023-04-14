#pragma once
#include "StateComponentBase.h"

namespace RB::PlayerStateComponents
{
	class TriggerMoveForward : public RB::States::StateComponentBase
	{
	public:
		TriggerMoveForward();
		~TriggerMoveForward() override;
		
	public:
		void OnUpdate() override;
	};
}