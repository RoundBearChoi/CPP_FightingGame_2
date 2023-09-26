#pragma once
#include "StateComponentBase.h"
#include "P0_Jab.h"

#include "iPlayerController.h"
#include "iPlayer.h"
#include "iInputController.h"

namespace RB::PlayerStateComponents
{
	class TriggerJab : public RB::States::StateComponentBase
	{
	public:
		TriggerJab() = default;
		~TriggerJab() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
	};
}