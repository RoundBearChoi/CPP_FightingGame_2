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
		TriggerJab(RB::States::iState* nextState);
		~TriggerJab() override;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
	};
}