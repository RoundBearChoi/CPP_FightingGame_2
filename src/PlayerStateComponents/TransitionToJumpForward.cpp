#include "TransitionToJumpForward.h"

namespace RB::PlayerStateComponents
{
	TransitionToJumpForward::TransitionToJumpForward(RB::States::iState* nextState, bool reverse)
	{
		_vecNextStates.push_back(nextState);

		_reverse = reverse;

	}

	void TransitionToJumpForward::OnEnter()
	{

	}

	void TransitionToJumpForward::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (playerController == nullptr || inputController == nullptr)
		{
			return;
		}

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		bool doJump = false;
		Input::iInputObj* inputObj = nullptr;

		if (!_reverse)
		{
			if (player->OtherPlayerIsOnRightSide())
			{
				doJump = inputController->IsHeld(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_RIGHT);
				inputObj = inputController->GetUnused_Movement_FIFO(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_RIGHT);
			}
			else
			{
				doJump = inputController->IsHeld(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_LEFT);
				inputObj = inputController->GetUnused_Movement_FIFO(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_LEFT);
			}
		}
		else
		{
			if (player->OtherPlayerIsOnRightSide())
			{
				doJump = inputController->IsHeld(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_LEFT);
				inputObj = inputController->GetUnused_Movement_FIFO(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_LEFT);
			}
			else
			{
				doJump = inputController->IsHeld(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_RIGHT);
				inputObj = inputController->GetUnused_Movement_FIFO(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_RIGHT);
			}
		}

		if (doJump)
		{
			if (inputObj != nullptr)
			{
				inputObj->SetUsedAsMovement(true);

				RB::States::iStateMachine* machine = player->GetStateMachine();
				machine->QueueNextState(_vecNextStates[0]);
			}
		}
	}
}
