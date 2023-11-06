#pragma once
#include "olcPixelGameEngine.h"
#include "StateComponentBase.h"
#include "Ease.h"

#include "iPlayerController.h"

#include "P0_Idle.h"

namespace RB::PlayerStateComponents
{
	class MoveDownOnFall : public RB::States::StateComponentBase
	{
	public:
		MoveDownOnFall(size_t totalFrames, float_t multiplier, RB::States::iState* nextState);
		~MoveDownOnFall() override;

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		size_t _totalFrames = 0;
		float_t _multiplier = 1.0f;
	};
}