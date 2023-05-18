#include "MoveForwardDetector.h"

namespace RB::PlayerStateComponents
{
	void MoveForwardDetector::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	void MoveForwardDetector::OnUpdate()
	{
		_getter_inputController.OnUpdate();
		_getter_playerController.OnUpdate();

		if (_getter_inputController.GetController() == nullptr || _getter_playerController.GetController() == nullptr)
		{
			return;
		}

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

	bool MoveForwardDetector::_MoveForwardPressed()
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