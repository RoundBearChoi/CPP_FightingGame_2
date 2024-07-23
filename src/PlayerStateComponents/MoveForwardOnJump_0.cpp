#include "MoveForwardOnJump_0.h"

namespace RB::PlayerStateComponents
{
	MoveForwardOnJump_0::MoveForwardOnJump_0(unsigned int totalFrames, float multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	void MoveForwardOnJump_0::OnEnter()
	{

	}

	void MoveForwardOnJump_0::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//get move amount (t is from 0 to 0.5, first half only)
		unsigned int frame = _state->GetCumulatedFixedUpdates();

		float t = (float)frame / ((float)_totalFrames * 2.0f);

		if (t >= 0.5f)
		{
			t = 0.5f;
		}
		else if (t <= 0.0f)
		{
			t = 0.0f;
		}

		float percentage = RB::Ease::EaseOutCirc(t);
		float result = percentage * _multiplier;

		if (!player->IsFacingRight())
		{
			result *= -1.0f;
		}

		//apply move
		player->Move({ result, 0.0f });
	}
}
