#include "WhileMovingBack.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingBack::OnEnter()
	{
		_moveForward.SetStateMachineID(_state->GetStateMachineID());
		_moveBack.SetStateMachineID(_state->GetStateMachineID());
	}

	void WhileMovingBack::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		_bKeepMoving = false;
		_bMoveForward = false;

		_moveForward.OnUpdate();
		_moveBack.OnUpdate();

		if (_moveForward.ProcMoveForward())
		{
			_bMoveForward = true;
			_bKeepMoving = false;

			return;
		}

		if (_moveBack.ProcMoveBack())
		{
			_bMoveForward = false;
			_bKeepMoving = true;

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

		if (_bKeepMoving)
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

		if (!_bKeepMoving)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_Idle());

			return;
		}
	}
}