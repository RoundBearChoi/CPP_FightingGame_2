#include "MoveBackOnPress.h"

namespace RB::PlayerStateComponents
{
	void MoveBackOnPress::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	void MoveBackOnPress::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return;
		}

		//false by default
		_bMoveBack = false;

		if (_BothPressed())
		{
			_bMoveBack = false;

			return;
		}

		if (_MoveBackPressed())
		{
			_bMoveBack = true;

			return;
		}
	}

	bool MoveBackOnPress::ProcMoveBack()
	{
		return _bMoveBack;
	}

	bool MoveBackOnPress::_BothPressed()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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

	bool MoveBackOnPress::_MoveBackPressed()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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