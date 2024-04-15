#include "MoveHorizontalOnFixedUpdateCount.h"

#include "olcPixelGameEngine.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	MoveHorizontalOnFixedUpdateCount::MoveHorizontalOnFixedUpdateCount(int fixedUpdateOnCount, float move)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_moveAmount = move;
	}

	void MoveHorizontalOnFixedUpdateCount::OnEnter()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		_otherPlayerIsOnRightSide = player->OtherPlayerIsOnRightSide();
	}

	void MoveHorizontalOnFixedUpdateCount::OnUpdate()
	{

	}

	void MoveHorizontalOnFixedUpdateCount::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		float move = _moveAmount;

		if (_otherPlayerIsOnRightSide)
		{
			//do nothing
		}
		else
		{
			move *= -1;
		}

		player->Move(olc::vf2d{ move, 0 });
	}
}