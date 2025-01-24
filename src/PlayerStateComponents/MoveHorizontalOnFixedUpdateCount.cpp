#include "MoveHorizontalOnFixedUpdateCount.h"

namespace RB::PlayerStateComponents
{
	MoveHorizontalOnFixedUpdateCount::MoveHorizontalOnFixedUpdateCount(int fixedUpdateOnCount, float move)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_moveAmount = move;
	}

	void MoveHorizontalOnFixedUpdateCount::OnEnter()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		_otherPlayerIsOnRightSide = player->OtherPlayerIsOnRightSide();
	}

	void MoveHorizontalOnFixedUpdateCount::OnUpdate()
	{

	}

	void MoveHorizontalOnFixedUpdateCount::OnFixedUpdate()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		float move = _moveAmount;

		if (_otherPlayerIsOnRightSide)
		{
			//do nothing
		}
		else
		{
			move *= -1.0f;
		}

		player->Move(RB::Vector2{ move, 0.0f });
	}
}
