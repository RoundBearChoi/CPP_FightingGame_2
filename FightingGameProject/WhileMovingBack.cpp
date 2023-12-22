#include "WhileMovingBack.h"

namespace RB::PlayerStateComponents
{
	WhileMovingBack::WhileMovingBack(int32_t speed, RB::States::iState* nextIdleState, RB::States::iState* nextWalkForwardState)
	{
		_speed = speed;
		_vecNextStates.push_back(nextIdleState);
		_vecNextStates.push_back(nextWalkForwardState);
	}

	void WhileMovingBack::OnEnter()
	{
		_moveForwardOnPress.SetStateMachineID(_state->GetStateMachineID());
		_moveBackOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void WhileMovingBack::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
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
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		if (_bMoveBack)
		{
			int32_t movement = _speed;

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
			stateMachine->QueueNextState(_vecNextStates[1]); //transition to walk forward

			return;
		}

		if (!_bMoveBack)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(_vecNextStates[0]); //transition to idle

			return;
		}
	}
}