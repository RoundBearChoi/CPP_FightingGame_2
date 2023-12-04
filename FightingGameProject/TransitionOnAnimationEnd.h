#pragma once
#include "StateComponentBase.h"

#include "P0_Idle.h"

#include "iPlayerController.h"
#include "iPlayerAnimationController.h"

namespace RB::PlayerStateComponents
{
	class TransitionOnAnimationEnd : public RB::States::StateComponentBase
	{
	public:
		TransitionOnAnimationEnd(RB::States::iState* nextState);
		~TransitionOnAnimationEnd() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;
	};
}