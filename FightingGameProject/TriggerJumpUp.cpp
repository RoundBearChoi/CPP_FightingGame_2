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
		RB::Players::PlayerID playerID = player->GetPlayerID();

		olc::HWButton jump = RB::Input::INPUT_CONTROLLER->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_JumpUp());

			return;
		}
	}
}