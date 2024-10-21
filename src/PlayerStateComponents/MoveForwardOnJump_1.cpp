#include "MoveForwardOnJump_1.h"

namespace RB::PlayerStateComponents
{
	MoveForwardOnJump_1::MoveForwardOnJump_1(unsigned int totalFrames, float multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	void MoveForwardOnJump_1::OnEnter()
	{

	}

	void MoveForwardOnJump_1::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//get move amount
		unsigned int frame = _state->GetCumulatedFixedUpdates();

		float percentage = (float)frame / ((float)_totalFrames * 2.0f);

		//start from 0.5 (second half only)
		percentage += 0.5f;

		if (percentage <= 0.5f)
		{
			percentage = 0.5f;
		}
		else if (percentage >= 1.0f)
		{
			percentage = 1.0f;
		}

		float amount = RB::Ease::EaseOutCirc(percentage);
		float result = amount * _multiplier;

		if (!player->IsFacingRight())
		{
			result *= -1.0f;
		}

		//apply move
		player->Move({ result, 0.0f });
	}
}
