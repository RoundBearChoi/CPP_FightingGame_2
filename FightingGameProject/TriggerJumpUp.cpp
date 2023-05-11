#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{
		_inputController = RB::Controllers::Controllers::GetController<RB::Input::InputController>();

		RB::Players::PlayerController* pc = RB::Controllers::Controllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_state->GetStateMachine()->GetID());
	}

	void TriggerJumpUp::OnUpdate()
	{
		RB::Players::PlayerID playerID = _ownerPlayer->GetPlayerID();

		olc::HWButton jump = _inputController->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			_state->QueueNextState(new RB::P0_States::P0_JumpUp());

			return;
		}
	}
}