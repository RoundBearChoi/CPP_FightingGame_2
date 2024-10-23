#include "MoveForwardOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveForwardOnJump::MoveForwardOnJump(unsigned int totalFrames, float multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	void MoveForwardOnJump::OnEnter()
	{

	}

	void MoveForwardOnJump::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		//get move amount (t is from 0 to 0.5, first half only)
		unsigned int frame = _state->GetCumulatedFixedUpdates();

		float percentage = (float)frame / (float)_totalFrames;

		if (percentage >= 1.0f)
		{
			percentage = 1.0f;
		}
		else if (percentage <= 0.0f)
		{
			percentage = 0.0f;
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
