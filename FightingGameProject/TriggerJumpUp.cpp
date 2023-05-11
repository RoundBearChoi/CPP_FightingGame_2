#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{
		RB::Controllers::iController* ic = RB::Controllers::CurrentControllers::GetController(typeid(RB::Input::InputController));
		_inputController = dynamic_cast<RB::Input::InputController*>(ic);
	}

	void TriggerJumpUp::OnUpdate()
	{
		RB::Players::iPlayer* player = _state->GetOwnerPlayer();
		RB::Players::PlayerID playerID = player->GetPlayerID();

		olc::HWButton jump = _inputController->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			_state->QueueNextState(new RB::P0_States::P0_JumpUp());

			return;
		}
	}
}