#include "WhileMovingForward.h"

namespace RB::PlayerStateComponents
{
	WhileMovingForward::WhileMovingForward()
	{

	}
	WhileMovingForward::~WhileMovingForward()
	{

	}

	void WhileMovingForward::OnEnter()
	{
		_moveForwardDetector.Init(_state->GetOwnerPlayer());
		_moveBackDetector.Init(_state->GetOwnerPlayer());
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

			if (_state->GetOwnerPlayer()->OtherPlayerIsOnRightSide())
			{
				movement = 2;
			}
			else
			{
				movement = -2;
			}

			_state->GetOwnerPlayer()->Move(olc::vi2d{ movement, 0 });

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