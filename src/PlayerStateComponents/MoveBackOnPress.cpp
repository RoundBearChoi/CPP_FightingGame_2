#include "MoveBackOnPress.h"

namespace RB::PlayerStateComponents
{
	void MoveBackOnPress::SetStateMachineID(unsigned int id)
	{
		_stateMachineID = id;
	}

	void MoveBackOnPress::OnUpdate()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (playerController == nullptr || inputController == nullptr)
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
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = inputController->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = inputController->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeftHeld && moveRightHeld)
		{
			return true;
		}

		return false;
	}

	bool MoveBackOnPress::_MoveBackPressed()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = inputController->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = inputController->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (player->OtherPlayerIsOnRightSide())
		{
			if (moveLeftHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveRightHeld)
			{
				return true;
			}
		}

		return false;
	}
}