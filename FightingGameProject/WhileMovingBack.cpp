#include "WhileMovingBack.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingBack::OnEnter()
	{
		_moveForwardOnPress.SetStateMachineID(_state->GetStateMachineID());
		_moveBackOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void WhileMovingBack::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		_bMoveBack = false;
		_bMoveForward = false;

		_moveForwardOnPress.OnUpdate();
		_moveBackOnPress.OnUpdate();

		if (_moveForwardOnPress.ProcMoveForward())
		{
			_bMoveForward = true;
			_bMoveBack = false;

			return;
		}

		if (_moveBackOnPress.ProcMoveBack())
		{
			_bMoveForward = false;
			_bMoveBack = true;

			return;
		}
	}
	void WhileMovingBack::OnFixedUpdate()
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

		if (_bMoveBack)
		{
			int movement = 0;

			if (player->OtherPlayerIsOnRightSide())
			{
				movement = -2;
			}
			else
			{
				movement = 2;
			}

			player->Move(olc::vi2d{ movement, 0 });

			return;
		}

		if (_bMoveForward)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveForward());

			return;
		}

		if (!_bMoveBack)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_Idle());

			return;
		}
	}
}