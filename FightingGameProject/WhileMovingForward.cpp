#include "WhileMovingForward.h"

namespace RB::PlayerStateComponents
{
	void WhileMovingForward::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::CurrentControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_state->GetStateMachine()->GetID());

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
			int movement = 0;

			if (_ownerPlayer->OtherPlayerIsOnRightSide())
			{
				movement = 2;
			}
			else
			{
				movement = -2;
			}

			_ownerPlayer->Move(olc::vi2d{ movement, 0 });

			return;
		}

		if (_moveBack)
		{
			_state->GetStateMachine()->QueueNextState(new RB::P0_States::P0_MoveBack());

			return;
		}

		if (!_keepMoving)
		{
			_state->QueueNextState(new RB::P0_States::P0_Idle());

			return;
		}
	}
}