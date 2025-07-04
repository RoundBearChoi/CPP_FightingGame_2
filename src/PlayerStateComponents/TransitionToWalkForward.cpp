#include "TransitionToWalkForward.h"

namespace RB::PlayerStateComponents
{
	TransitionToWalkForward::TransitionToWalkForward(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);
	}

	void TransitionToWalkForward::OnEnter()
	{
		_moveForwardOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void TransitionToWalkForward::OnUpdate()
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

		_moveForwardOnPress.OnUpdate();

		if (_moveForwardOnPress.ProcMoveForward())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(_vecNextStates[0]);
		}
	}
}
