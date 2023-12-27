#pragma once
#include "olcPixelGameEngine.h"
#include "StateComponentBase.h"
#include "SpriteEnum.h"
#include "Ease.h"

#include "iPlayer.h"
#include "P0_JumpUp_1.h"

#include "iSpecsController.h"

namespace RB::PlayerStateComponents
{
	class MoveUpOnJump : public RB::States::StateComponentBase
	{
	public:
		MoveUpOnJump(unsigned int totalFrames, float multiplier, RB::States::iState* nextState);
		~MoveUpOnJump() override;

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		unsigned int _totalFrames = 0;
		float _multiplier = 1.0f;
	};
}