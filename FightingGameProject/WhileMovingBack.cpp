#include "WhileMovingBack.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingBack::OnEnter()
	{
		_moveForwardDetector.SetStateMachineID(_state->GetStateMachineID());
		_moveBackDetector.SetStateMachineID(_state->GetStateMachineID());
	}

	void WhileMovingBack::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		_keepMoving = false;
		_moveForward = false;

		_moveForwardDetector.OnUpdate();
		_moveBackDetector.OnUpdate();

		if (_moveForwardDetector.MoveForward())
		{
			_moveForward = true;
			_keepMoving = false;

			return;
		}

		if (_moveBackDetector.MoveBack())
		{
			_moveForward = false;
			_keepMoving = true;

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

		if (_keepMoving)
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

		if (_moveForward)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveForward());

			return;
		}

		if (!_keepMoving)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_Idle());

			return;
		}
	}
}