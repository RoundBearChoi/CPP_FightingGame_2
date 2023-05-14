#include "WhileMovingBack.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingBack::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_moveForwardDetector.Init(_ownerPlayer);
		_moveBackDetector.Init(_ownerPlayer);
	}

	void WhileMovingBack::OnUpdate()
	{
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
		if (_keepMoving)
		{
			int movement = 0;

			if (_ownerPlayer->OtherPlayerIsOnRightSide())
			{
				movement = -2;
			}
			else
			{
				movement = 2;
			}

			_ownerPlayer->Move(olc::vi2d{ movement, 0 });

			return;
		}

		if (_moveForward)
		{
			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();
			machine->QueueNextState(new RB::P0_States::P0_MoveForward());

			return;
		}

		if (!_keepMoving)
		{
			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();

			machine->QueueNextState(new RB::P0_States::P0_Idle());

			return;
		}
	}
}