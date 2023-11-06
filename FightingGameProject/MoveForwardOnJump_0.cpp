#include "MoveForwardOnJump_0.h"

namespace RB::PlayerStateComponents
{
	MoveForwardOnJump_0::MoveForwardOnJump_0(size_t totalFrames, float_t multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	void MoveForwardOnJump_0::OnEnter()
	{

	}

	void MoveForwardOnJump_0::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//get move amount (t is from 0 to 0.5, first half only)
		size_t frame = _state->GetCumulatedFixedUpdates();

		float_t t = (float_t)frame / ((float_t)_totalFrames * 2.0f);

		if (t >= 0.5f)
		{
			t = 0.5f;
		}
		else if (t <= 0.0f)
		{
			t = 0.0f;
		}

		float_t percentage = RB::EaseEquations::Ease::EaseOutCirc(t);
		float_t result = percentage * _multiplier;

		if (!player->IsFacingRight()) //OtherPlayerIsOnRightSide())
		{
			result *= -1.0f;
		}

		//apply move
		player->Move({ (int32_t)result, 0 });
	}
}