#include "MoveForwardOnFixedUpdateCount.h"

namespace RB::PlayerStateComponents
{
	MoveForwardOnFixedUpdateCount::MoveForwardOnFixedUpdateCount(int32_t fixedUpdateOnCount)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
	}

	void MoveForwardOnFixedUpdateCount::OnEnter()
	{

	}

	void MoveForwardOnFixedUpdateCount::OnUpdate()
	{

	}

	void MoveForwardOnFixedUpdateCount::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		int32_t movement = 4;

		if (player->OtherPlayerIsOnRightSide())
		{
			
		}
		else
		{
			movement *= -1;
		}

		player->Move(olc::vi2d{ movement, 0 });
	}
}