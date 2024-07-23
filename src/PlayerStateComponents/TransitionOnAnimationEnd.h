#pragma once

#include "../StateComponentBase.h"
#include "../Render/AnimationSpecs.h"
#include "../Players/PlayerState.h"

#include "../iState.h"
#include "../Players/iPlayerController.h"
#include "../Render/iPlayerAnimationController.h"

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
