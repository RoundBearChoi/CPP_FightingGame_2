#pragma once

#include "../Ease.h"
#include "../Vector2.h"
#include "../StateComponentBase.h"

#include "../iState.h"
#include "../Players/iPlayerController.h"

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
