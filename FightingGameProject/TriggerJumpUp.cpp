#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{
		_inputController = RB::Controllers::ActiveControllers::GetController<RB::Input::InputController>();

		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_state->GetStateMachineID());
	}

	void TriggerJumpUp::OnUpdate()
	{
		RB::Players::PlayerID playerID = _ownerPlayer->GetPlayerID();

		olc::HWButton jump = _inputController->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();
			machine->QueueNextState(new RB::P0_States::P0_JumpUp());

			return;
		}
	}
}