#include "WhileMovingForward.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingForward::OnEnter()
	{
		_moveForwardOnPress.SetStateMachineID(_state->GetStateMachineID());
		_moveBackOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void WhileMovingForward::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
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
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		if (_bMoveForward)
		{
			int movement = 3;

			if (player->OtherPlayerIsOnRightSide())
			{
				//normal movement
			}
			else
			{
				//reverse movement
				movement *= -1;
			}

			player->Move(olc::vi2d{ movement, 0 });

			return;
		}

		if (_bMoveBack)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveBack());

			return;
		}

		if (!_bMoveForward)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_Idle());

			return;
		}
	}
}