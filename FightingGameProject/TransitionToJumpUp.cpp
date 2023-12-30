#include "TransitionToJumpUp.h"

#include "iPlayerController.h"
#include "iInputController.h"

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
		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Input::iInputController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		bool jumpUp = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP);
		bool jumpForwardUp = false;

		if (player->OtherPlayerIsOnRightSide())
		{
			jumpForwardUp = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
		}
		else
		{
			jumpForwardUp = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
		}
		
		if (jumpUp && !jumpForwardUp)
		{
			RB::Input::iInputObj* jumpPress = RB::Input::iInputController::instance->GetUnused_Movement_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP);

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