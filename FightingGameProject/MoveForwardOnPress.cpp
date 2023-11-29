#include "MoveForwardOnPress.h"

namespace RB::PlayerStateComponents
{
	void MoveForwardOnPress::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	void MoveForwardOnPress::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return;
		}

		//false by default
		_bMoveForward = false;

		if (_BothPressed())
		{
			_bMoveForward = false;

			return;
		}

		if (_MoveForwardPressed())
		{
			_bMoveForward = true;

			return;
		}
	}

	bool MoveForwardOnPress::ProcMoveForward()
	{
		return _bMoveForward;
	}

	bool MoveForwardOnPress::_BothPressed()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = RB::Input::INPUT_CONTROLLER->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = RB::Input::INPUT_CONTROLLER->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		//olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		//olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeftHeld && moveRightHeld)
		{
			return true;
		}

		//if (moveLeft.bHeld && moveRight.bHeld)
		//{
		//	return true;
		//}

		return false;
	}

	bool MoveForwardOnPress::_MoveForwardPressed()
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