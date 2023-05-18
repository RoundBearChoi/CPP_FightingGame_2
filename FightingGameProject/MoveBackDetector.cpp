#include "MoveBackDetector.h"

namespace RB::PlayerStateComponents
{
	void MoveBackDetector::Init(RB::Players::iPlayer* player)
	{
		_player = player;
	}

	void MoveBackDetector::OnUpdate()
	{
		_getter_inputController.OnUpdate();

		if (_getter_inputController.GetController() == nullptr)
		{
			return;
		}

		//false by default
		_moveBack = false;

		if (_BothPressed())
		{
			_moveBack = false;

			return;
		}

		if (_MoveBackPressed())
		{
			_moveBack = true;

			return;
		}
	}

	bool MoveBackDetector::MoveBack()
	{
		return _moveBack;
	}

	bool MoveBackDetector::_BothPressed()
	{
		olc::HWButton moveLeft = _getter_inputController.GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = _getter_inputController.GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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

	bool MoveBackDetector::_MoveBackPressed()
	{
		olc::HWButton moveLeft = _getter_inputController.GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = _getter_inputController.GetController()->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (_player->OtherPlayerIsOnRightSide())
		{
			if (moveLeft.bPressed || moveLeft.bHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveRight.bPressed || moveRight.bHeld)
			{
				return true;
			}
		}

		return false;
	}
}