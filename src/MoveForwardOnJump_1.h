#pragma once

#include "Ease.h"
#include "StateComponentBase.h"

#include "Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardOnJump_1 : public RB::States::StateComponentBase
	{
	public:
		MoveForwardOnJump_1(unsigned int totalFrames, float multiplier);
		~MoveForwardOnJump_1() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		unsigned int _totalFrames = 0;
		float _multiplier = 0.0f;
	};
}
