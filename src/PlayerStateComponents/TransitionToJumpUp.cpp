#include "TransitionToJumpUp.h"

namespace RB::PlayerStateComponents
{
	TransitionToJumpUp::TransitionToJumpUp(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);
	}

	void TransitionToJumpUp::OnEnter()
	{

	}

	void TransitionToJumpUp::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (playerController == nullptr || inputController == nullptr)
		{
			return;
		}

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(
			_state->GetStateMachineID());

		bool jumpUp = inputController->IsHeld(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP);

		bool jumpForwardUp = false;

		if (player->OtherPlayerIsOnRightSide())
		{
			jumpForwardUp = inputController->IsHeld(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_RIGHT);
		}
		else
		{
			jumpForwardUp = inputController->IsHeld(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP_LEFT);
		}
		
		if (jumpUp && !jumpForwardUp)
		{
			Input::iInputObj* jumpPress = inputController->GetUnused_Movement_FIFO(player->GetPLAYER_TYPE(), Input::PlayerInput::MOVE_UP);

			if (jumpPress != nullptr)
			{
				jumpPress->SetUsedAsMovement(true);

				RB::States::iStateMachine* machine = player->GetStateMachine();
				
				machine->QueueNextState(_vecNextStates[0]);

				return;
			}
		}
	}
}
