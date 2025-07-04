#include "MoveForwardOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveForwardOnJump::MoveForwardOnJump(unsigned int totalFrames, float multiplier, MoveForwardOnJumpType jumpType)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
		_jumpType = jumpType;
	}

	void MoveForwardOnJump::OnEnter()
	{

	}

	void MoveForwardOnJump::OnFixedUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		//get move amount (t is from 0 to 0.5, first half only)
		unsigned int frame = _state->GetCumulatedFixedUpdates();

		float percentage = (float)frame / (float)_totalFrames;

		if (_jumpType == MoveForwardOnJumpType::FIRST_HALF)
		{
			percentage *= 0.5f;

			if (percentage >= 0.5f)
			{
				percentage = 0.5f;
			}
		}
		else if (_jumpType == MoveForwardOnJumpType::SECOND_HALF)
		{
			percentage *= 0.5f;
			percentage += 0.5f;

			if (percentage >= 1.0f)
			{
				percentage = 1.0f;
			}
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
