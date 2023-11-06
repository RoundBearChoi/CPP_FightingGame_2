#pragma once
#include <cmath>
#include "StateComponentBase.h"
#include "Ease.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardOnJump_1 : public RB::States::StateComponentBase
	{
	public:
		MoveForwardOnJump_1(size_t totalFrames, float_t multiplier);
		~MoveForwardOnJump_1() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		size_t _totalFrames = 0;
		float_t _multiplier = 0.0f;
	};
}