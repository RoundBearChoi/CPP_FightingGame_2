#pragma once

#include "Render/AnimationSpecs.h"
#include "StateComponentBase.h"
#include "PlayerState.h"

#include "iState.h"
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
