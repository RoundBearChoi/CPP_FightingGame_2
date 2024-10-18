#pragma once

#include "../Ease.h"
#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveUpOnJump : public RB::States::StateComponentBase
	{
	public:
		MoveUpOnJump(unsigned int totalFrames, float multiplier);
		~MoveUpOnJump() override;

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		unsigned int _totalFrames = 0;
		float _multiplier = 1.0f;
	};
}
