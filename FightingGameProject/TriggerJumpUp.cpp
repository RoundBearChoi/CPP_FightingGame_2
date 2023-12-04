#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{

	}

	void TriggerJumpUp::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::iInputController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

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
			RB::Input::iInputObj* jumpPress = RB::Input::iInputController::instance->GetUnusedInputObj_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP);

			if (jumpPress != nullptr)
			{
				jumpPress->SetUsedStatus(true);

				RB::States::iStateMachine* machine = player->GetStateMachine();
				machine->QueueNextState(new RB::PlayerStates::P0_JumpUp());

				return;
			}
		}
	}
}