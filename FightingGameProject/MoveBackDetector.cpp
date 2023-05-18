#include "MoveBackDetector.h"

namespace RB::PlayerStateComponents
{
	void MoveBackDetector::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	void MoveBackDetector::OnUpdate()
	{
		_getter_inputController.OnUpdate();
		_getter_playerController.OnUpdate();

		if (_getter_inputController.GetController() == nullptr || _getter_playerController.GetController() == nullptr)
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
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = _getter_inputController.GetController()->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = _getter_inputController.GetController()->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = _getter_inputController.GetController()->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = _getter_inputController.GetController()->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (player->OtherPlayerIsOnRightSide())
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