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
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr ||
			RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(
			_state->GetStateMachineID());

		bool jumpUp = RB::Input::iInputController::Get()->IsHeld(
			player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP);
		bool jumpForwardUp = false;

		if (player->OtherPlayerIsOnRightSide())
		{
			jumpForwardUp = RB::Input::iInputController::Get()->IsHeld(
				player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
		}
		else
		{
			jumpForwardUp = RB::Input::iInputController::Get()->IsHeld(
				player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
		}
		
		if (jumpUp && !jumpForwardUp)
		{
			RB::Input::iInputObj* jumpPress = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(
				player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP);

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
