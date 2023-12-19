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
		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Input::iInputController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		bool jumpForward = false;
		RB::Input::iInputObj* jumpForwardInputObj = nullptr;

		if (player->OtherPlayerIsOnRightSide())
		{
			jumpForward = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
			jumpForwardInputObj = RB::Input::iInputController::instance->GetUnusedInputObj_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
		}
		else
		{
			jumpForward = RB::Input::iInputController::instance->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
			jumpForwardInputObj = RB::Input::iInputController::instance->GetUnusedInputObj_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
		}

		if (jumpForward)
		{
			if (jumpForwardInputObj != nullptr)
			{
				jumpForwardInputObj->SetUsedStatus(true);

				RB::States::iStateMachine* machine = player->GetStateMachine();
				machine->QueueNextState(_vecNextStates[0]);
			}
		}
	}
}