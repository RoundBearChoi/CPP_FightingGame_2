#include "WhileMovingForward.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingForward::OnEnter()
	{
		_moveForwardDetector.SetStateMachineID(_state->GetStateMachineID());
		_moveBackDetector.SetStateMachineID(_state->GetStateMachineID());
	}

	void WhileMovingForward::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		_keepMoving = false;
		_moveBack = false;

		_moveForwardDetector.OnUpdate();
		_moveBackDetector.OnUpdate();

		if (_moveBackDetector.MoveBack())
		{
			_moveBack = true;
			_keepMoving = false;

			return;
		}

		if (_moveForwardDetector.MoveForward())
		{
			_moveBack = false;
			_keepMoving = true;

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

		if (_keepMoving)
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

		if (_moveBack)
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();
			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveBack());

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