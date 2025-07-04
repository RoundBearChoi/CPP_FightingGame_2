#include "TransitionOnDeath.h"

#include "../Updaters/CurrentPlayground.h"

namespace RB::PlayerStateComponents
{
	TransitionOnDeath::TransitionOnDeath(int fixedUpdateOnCount, RB::States::iState* nextState)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_vecNextStates.push_back(nextState);
	}
	void TransitionOnDeath::OnEnter()
	{

	}

	void TransitionOnDeath::OnUpdate()
	{

	}

	void TransitionOnDeath::OnFixedUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player->GetHP() <= 0)
		{
			player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
		}
	}
}
