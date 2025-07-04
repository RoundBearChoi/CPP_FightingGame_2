#include "TransitionOnFixedUpdateCount.h"

namespace RB::PlayerStateComponents
{
	TransitionOnFixedUpdateCount::TransitionOnFixedUpdateCount(int fixedUpdateOnCount, RB::States::iState* nextState)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_vecNextStates.push_back(nextState);
	}
	void TransitionOnFixedUpdateCount::OnEnter()
	{

	}

	void TransitionOnFixedUpdateCount::OnUpdate()
	{

	}

	void TransitionOnFixedUpdateCount::OnFixedUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		// only if player isn't dead
		if (player->GetHP() > 0)
		{
			player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
		}
	}
}
