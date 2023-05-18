#include "WhileMovingForward.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingForward::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_moveForwardDetector.Init(_ownerPlayer);
		_moveBackDetector.Init(_ownerPlayer);
	}

	void WhileMovingForward::OnUpdate()
	{
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
		if (_keepMoving)
		{
			int movement = 3;

			if (_ownerPlayer->OtherPlayerIsOnRightSide())
			{
				//normal movement
			}
			else
			{
				//reverse movement
				movement *= -1;
			}

			_ownerPlayer->Move(olc::vi2d{ movement, 0 });

			return;
		}

		if (_moveBack)
		{
			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_MoveBack());

			return;
		}

		if (!_keepMoving)
		{
			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();

			machine->QueueNextState(new RB::PlayerStates::P0_Idle());

			return;
		}
	}
}