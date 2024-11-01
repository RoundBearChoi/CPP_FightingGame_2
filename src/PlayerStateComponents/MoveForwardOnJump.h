#pragma once

#include "../Ease.h"
#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"

#include "MoveForwardOnJumpType.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardOnJump : public RB::States::StateComponentBase
	{
	public:
		MoveForwardOnJump(unsigned int totalFrames, float multiplier, MoveForwardOnJumpType jumpType);
		~MoveForwardOnJump() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		unsigned int _totalFrames = 0;
		float _multiplier = 0.0f;
		MoveForwardOnJumpType _jumpType = MoveForwardOnJumpType::NONE;
	};
}
