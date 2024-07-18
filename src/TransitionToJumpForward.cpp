#include "TransitionToJumpForward.h"

namespace RB::PlayerStateComponents
{
	TransitionToJumpForward::TransitionToJumpForward(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);
	}

	void TransitionToJumpForward::OnEnter()
	{

	}

	void TransitionToJumpForward::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr ||
			RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		bool jumpForward = false;
		RB::Input::iInputObj* jumpForwardInputObj = nullptr;

		if (player->OtherPlayerIsOnRightSide())
		{
			jumpForward = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
			jumpForwardInputObj = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
		}
		else
		{
			jumpForward = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
			jumpForwardInputObj = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
		}

		if (jumpForward)
		{
			if (jumpForwardInputObj != nullptr)
			{
				jumpForwardInputObj->SetUsedAsMovement(true);

				RB::States::iStateMachine* machine = player->GetStateMachine();
				machine->QueueNextState(_vecNextStates[0]);
			}
		}
	}
}
