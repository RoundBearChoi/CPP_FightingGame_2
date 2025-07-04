#include "TransitionToWalkBack.h"

namespace RB::PlayerStateComponents
{
	TransitionToWalkBack::TransitionToWalkBack(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);
	}

	void TransitionToWalkBack::OnEnter()
	{
		_moveBackOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void TransitionToWalkBack::OnUpdate()
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

		_moveBackOnPress.OnUpdate();

		if (_moveBackOnPress.ProcMoveBack())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(_vecNextStates[0]);
		}
	}
}
