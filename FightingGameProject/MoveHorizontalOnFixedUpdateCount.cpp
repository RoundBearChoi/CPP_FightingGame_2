#include "MoveHorizontalOnFixedUpdateCount.h"

namespace RB::PlayerStateComponents
{
	MoveHorizontalOnFixedUpdateCount::MoveHorizontalOnFixedUpdateCount(int32_t fixedUpdateOnCount, bool forward, int32_t move)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_bForward = forward;
		_moveAmount = move;
	}

	void MoveHorizontalOnFixedUpdateCount::OnEnter()
	{

	}

	void MoveHorizontalOnFixedUpdateCount::OnUpdate()
	{

	}

	void MoveHorizontalOnFixedUpdateCount::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (_moveAmount < 0)
		{
			_moveAmount *= -1;
		}

		if (player->OtherPlayerIsOnRightSide())
		{
			if (_bForward)
			{

			}
			else
			{
				_moveAmount *= -1;
			}
		}
		else
		{
			if (_bForward)
			{
				_moveAmount *= -1;
			}
			else
			{

			}
		}

		player->Move(olc::vi2d{ _moveAmount, 0 });
	}
}