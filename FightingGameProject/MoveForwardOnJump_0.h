#pragma once

#include "StateComponentBase.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardOnJump_0 : public RB::States::StateComponentBase
	{
	public:
		MoveForwardOnJump_0(unsigned int totalFrames, float multiplier);
		~MoveForwardOnJump_0() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		unsigned int _totalFrames = 0;
		float _multiplier = 0.0f;
	};
}