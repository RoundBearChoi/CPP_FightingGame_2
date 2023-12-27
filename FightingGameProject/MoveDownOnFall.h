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
		MoveDownOnFall(unsigned int totalFrames, float multiplier, RB::States::iState* nextState);
		~MoveDownOnFall() override;

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	private:
		unsigned int _totalFrames = 0;
		float _multiplier = 1.0f;
	};
}