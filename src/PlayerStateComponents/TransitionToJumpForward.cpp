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
		if (RB::Players::iPlayerController::Get() == nullptr ||
			RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		bool doJump = false;
		RB::Input::iInputObj* inputObj = nullptr;

		if (!_reverse)
		{
			if (player->OtherPlayerIsOnRightSide())
			{
				doJump = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
				inputObj = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
			}
			else
			{
				doJump = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
				inputObj = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
			}
		}
		else
		{
			if (player->OtherPlayerIsOnRightSide())
			{
				doJump = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
				inputObj = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_LEFT);
			}
			else
			{
				doJump = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
				inputObj = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP_RIGHT);
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
