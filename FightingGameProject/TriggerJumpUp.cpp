#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{

	}

	void TriggerJumpUp::OnUpdate()
	{
		if (RB::Players::PlayerController::PTR == nullptr ||
			RB::Input::InputController::PTR == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PlayerController::PTR->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerID playerID = player->GetPlayerID();

		olc::HWButton jump = RB::Input::InputController::PTR->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_JumpUp());

			return;
		}
	}
}