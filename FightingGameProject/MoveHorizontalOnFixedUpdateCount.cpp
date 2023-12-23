#include "MoveHorizontalOnFixedUpdateCount.h"

namespace RB::PlayerStateComponents
{
	MoveHorizontalOnFixedUpdateCount::MoveHorizontalOnFixedUpdateCount(int32_t fixedUpdateOnCount, int32_t move)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_moveAmount = move;
	}

	void MoveHorizontalOnFixedUpdateCount::OnEnter()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		_otherPlayerIsOnRightSide = player->OtherPlayerIsOnRightSide();
	}

	void MoveHorizontalOnFixedUpdateCount::OnUpdate()
	{

	}

	void MoveHorizontalOnFixedUpdateCount::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		int32_t move = _moveAmount;

		if (_otherPlayerIsOnRightSide)
		{
			//do nothing
		}
		else
		{
			move *= -1;
		}

		player->Move(olc::vi2d{ move, 0 });
	}
}