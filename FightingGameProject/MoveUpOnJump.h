#pragma once
#include "olcPixelGameEngine.h"
#include "StateComponentBase.h"
#include "Ease.h"

#include "iPlayer.h"
#include "P0_FallDown.h"

namespace RB::PlayerStateComponents
{
	class MoveUpOnJump : public RB::States::StateComponentBase
	{
	public:
		MoveUpOnJump(size_t totalFrames);
		~MoveUpOnJump() override {};

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		size_t _totalFrames = 0;
	};
}