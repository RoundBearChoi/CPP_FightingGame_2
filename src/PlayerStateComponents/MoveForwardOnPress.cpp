#include "MoveForwardOnPress.h"

namespace RB::PlayerStateComponents
{
	void MoveForwardOnPress::SetStateMachineID(unsigned int id)
	{
		_stateMachineID = id;
	}

	void MoveForwardOnPress::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (playerController == nullptr || inputController == nullptr)
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
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = inputController->IsHeld(player->GetPLAYER_TYPE(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = inputController->IsHeld(player->GetPLAYER_TYPE(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeftHeld && moveRightHeld)
		{
			return true;
		}

		return false;
	}

	bool MoveForwardOnPress::_MoveForwardPressed()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = inputController->IsHeld(player->GetPLAYER_TYPE(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = inputController->IsHeld(player->GetPLAYER_TYPE(), RB::Input::PlayerInput::MOVE_RIGHT);

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
