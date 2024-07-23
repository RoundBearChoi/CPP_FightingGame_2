#pragma once

#include "../StateComponentBase.h"

#include "../States/iState.h"
#include "../Players/iPlayerController.h"
#include "../iInputController.h"

namespace RB::PlayerStateComponents
{
	class StandUpOnRelease : public RB::States::StateComponentBase
	{
	public:
		StandUpOnRelease(RB::States::iState* nextState);

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;
	};
}
