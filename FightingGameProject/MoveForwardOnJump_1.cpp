#include "MoveForwardOnJump_1.h"

namespace RB::PlayerStateComponents
{
	MoveForwardOnJump_1::MoveForwardOnJump_1(size_t totalFrames, float_t multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	void MoveForwardOnJump_1::OnEnter()
	{

	}

	void MoveForwardOnJump_1::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//get move amount
		size_t frame = _state->GetCumulatedFixedUpdates();

		float_t t = (float_t)frame / ((float_t)_totalFrames * 2.0f);

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

		float_t percentage = RB::EaseEquations::Ease::EaseOutCirc(t);
		float_t result = percentage * _multiplier;

		if (!player->OtherPlayerIsOnRightSide())
		{
			result *= -1.0f;
		}

		//apply move
		player->Move({ (int32_t)result, 0 });
	}
}