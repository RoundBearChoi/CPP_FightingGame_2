#include "MoveForward.h"

namespace RB::PlayerStateComponents
{
	void MoveForward::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	void MoveForward::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::INPUT_CONTROLLER == nullptr)
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

	bool MoveForward::ProcMoveForward()
	{
		return _moveForward;
	}

	bool MoveForward::_BothPressed()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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

	bool MoveForward::_MoveForwardPressed()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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