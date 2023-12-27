#include "MoveForwardOnPress.h"

namespace RB::PlayerStateComponents
{
	void MoveForwardOnPress::SetStateMachineID(unsigned int id)
	{
		_stateMachineID = id;
	}

	void MoveForwardOnPress::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Input::iInputController::instance == nullptr)
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
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeftHeld && moveRightHeld)
		{
			return true;
		}

		return false;
	}

	bool MoveForwardOnPress::_MoveForwardPressed()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (player->OtherPlayerIsOnRightSide())
		{
			if (moveRightHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveLeftHeld)
			{
				return true;
			}
		}

		return false;
	}
}