#include "MoveForwardOnJump_1.h"

#include "Ease.h"

#include "iPlayerController.h"

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
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//get move amount
		unsigned int frame = _state->GetCumulatedFixedUpdates();

		float t = (float)frame / ((float)_totalFrames * 2.0f);

		//start from 0.5 (second half only)
		t += 0.5f;

		if (t <= 0.5f)
		{
			t = 0.5f;
		}
		else if (t >= 1.0f)
		{
			t = 1.0f;
		}

		float percentage = RB::EaseEquations::Ease::EaseOutCirc(t);
		float result = percentage * _multiplier;

		if (!player->IsFacingRight())
		{
			result *= -1.0f;
		}

		//apply move
		player->Move({ result, 0.0f });
	}
}