#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{

	}

	void TriggerJumpUp::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		bool jumpHeld = RB::Input::INPUT_CONTROLLER->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP);
		bool forwardHeld = false;

		if (player->OtherPlayerIsOnRightSide())
		{
			forwardHeld = RB::Input::INPUT_CONTROLLER->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);
		}
		else
		{
			forwardHeld = RB::Input::INPUT_CONTROLLER->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		}
		
		if (jumpHeld && !forwardHeld)
		{
			RB::Input::iInputObj* jumpPress = RB::Input::INPUT_CONTROLLER->GetUnusedInputObj_FIFO(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_UP);

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