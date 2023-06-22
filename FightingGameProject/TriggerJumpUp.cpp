#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{

	}

	void TriggerJumpUp::OnUpdate()
	{
		_getter_inputController.OnUpdate();
		//_getter_playerController.OnUpdate();

		if (//_getter_playerController.GetController() == nullptr ||
			_getter_inputController.GetController() == nullptr)
		{
			return;
		}

		if (RB::Players::PlayerController::PTR == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PlayerController::PTR->GetPlayerOnStateMachineID(_state->GetStateMachineID()); //_getter_playerController.GetController()->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerID playerID = player->GetPlayerID();

		olc::HWButton jump = _getter_inputController.GetController()->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_JumpUp());

			return;
		}
	}
}