#include "WhileMovingForward.h"

namespace RB::PlayerStateComponents
{
	WhileMovingForward::WhileMovingForward(float speed, RB::States::iState* nextIdleState, RB::States::iState* nextWalkBackState)
	{
		_speed = speed;
		_vecNextStates.push_back(nextIdleState);
		_vecNextStates.push_back(nextWalkBackState);
	}

	void WhileMovingForward::OnEnter()
	{
		_moveForwardOnPress.SetStateMachineID(_state->GetStateMachineID());
		_moveBackOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void WhileMovingForward::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		_bMoveForward = false;
		_bMoveBack = false;

		_moveForwardOnPress.OnUpdate();
		_moveBackOnPress.OnUpdate();

		if (_moveBackOnPress.ProcMoveBack())
		{
			_bMoveBack = true;
			_bMoveForward = false;

			return;
		}

		if (_moveForwardOnPress.ProcMoveForward())
		{
			_bMoveBack = false;
			_bMoveForward = true;

			return;
		}
	}

	void WhileMovingForward::OnFixedUpdate()
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

		if (_bMoveForward)
		{
			float movement = _speed;

			if (player->OtherPlayerIsOnRightSide())
			{
				//normal movement
			}
			else
			{
				//reverse movement
				movement *= -1;
			}

			player->Move(RB::Vector2{ movement, 0.0f });

			return;
		}

		if (_bMoveBack)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(_vecNextStates[1]); //transition to walk back

			return;
		}

		if (!_bMoveForward)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(_vecNextStates[0]); //transition to idle

			return;
		}
	}
}
