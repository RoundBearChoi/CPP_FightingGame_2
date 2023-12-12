#include "WhileMovingForward.h"

namespace RB::PlayerStateComponents
{
	WhileMovingForward::WhileMovingForward(RB::States::iState* nextIdleState, RB::States::iState* nextWalkBackState)
	{
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
		if (RB::Players::iPlayerController::instance == nullptr)
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
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

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
			stateMachine->QueueNextState(_vecNextStates[1]); //new RB::PlayerStates::P0_MoveBack());

			return;
		}

		if (!_bMoveForward)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(_vecNextStates[0]); //new RB::PlayerStates::P0_Idle());

			return;
		}
	}
}