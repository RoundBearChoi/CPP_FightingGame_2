#include "MoveForwardDetector.h"

namespace RB::PlayerStateComponents
{
	void MoveForwardDetector::Init(RB::Players::iPlayer* player)
	{
		_player = player;
	}

	void MoveForwardDetector::OnUpdate()
	{
		//false by default
		_moveForward = false;

		if (_BothPressed())
		{
			_moveForward = false;

			return;
		}

		if (_MoveForwardPressed())
		{
			_moveForward = true;

			return;
		}
	}

	bool MoveForwardDetector::MoveForward()
	{
		return _moveForward;
	}

	bool MoveForwardDetector::_BothPressed()
	{
		olc::HWButton moveLeft = RB::Input::CurrentInputController::GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::CurrentInputController::GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeft.bPressed && moveRight.bPressed)
		{
			return true;
		}
		if (moveLeft.bHeld && moveRight.bHeld)
		{
			return true;
		}
		return false;
	}

	bool MoveForwardDetector::_MoveForwardPressed()
	{
		olc::HWButton moveLeft = RB::Input::CurrentInputController::GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::CurrentInputController::GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (_player->OtherPlayerIsOnRightSide())
		{
			if (moveRight.bPressed || moveRight.bHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveLeft.bPressed || moveLeft.bHeld)
			{
				return true;
			}
		}
		return false;
	}
}