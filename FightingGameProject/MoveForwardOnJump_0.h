#pragma once
#include <cmath>
#include "StateComponentBase.h"
#include "Ease.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardOnJump_0 : public RB::States::StateComponentBase
	{
	public:
		MoveForwardOnJump_0(size_t totalFrames, float_t multiplier);
		~MoveForwardOnJump_0() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		size_t _totalFrames = 0;
		float_t _multiplier = 0.0f;
	};
}