#include "MoveForwardDetector.h"

namespace RB::PlayerStateComponents
{
	void MoveForwardDetector::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	void MoveForwardDetector::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::InputController::PTR == nullptr)
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
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::InputController::PTR->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::InputController::PTR->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::InputController::PTR->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::InputController::PTR->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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