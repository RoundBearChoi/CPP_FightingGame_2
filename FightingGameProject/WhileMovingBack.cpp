#include "WhileMovingBack.h"

namespace RB::PlayerStateComponents
{
	WhileMovingBack::WhileMovingBack()
	{

	}

	WhileMovingBack::~WhileMovingBack()
	{

	}

	void WhileMovingBack::OnEnter()
	{
		_moveForwardDetector.Init(_state->GetOwnerPlayer());
		_moveBackDetector.Init(_state->GetOwnerPlayer());
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

			if (_state->GetOwnerPlayer()->OtherPlayerIsOnRightSide())
			{
				movement = -2;
			}
			else
			{
				movement = 2;
			}

			_state->GetOwnerPlayer()->Move(olc::vi2d{ movement, 0 });

			return;
		}

		if (_moveForward)
		{
			_state->GetStateMachine()->QueueNextState(new RB::Player0_States::P0_MoveForward());

			return;
		}

		if (!_keepMoving)
		{
			_state->QueueNextState(new RB::Player0_States::P0_Idle());

			return;
		}
	}
}