#include "TriggerJumpForward.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpForward::OnEnter()
	{

	}

	void TriggerJumpForward::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::iInputController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

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
				machine->QueueNextState(new RB::PlayerStates::P0_JumpForwardUp_0());
			}
		}
	}
}