#pragma once

#include "../States/StateComponentBase.h"

#include "../States/iState.h"
#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TransitionOnDeath : public RB::States::StateComponentBase
	{
	public:
		TransitionOnDeath(int fixedUpdateOnCount, RB::States::iState* nextState);
		~TransitionOnDeath() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}