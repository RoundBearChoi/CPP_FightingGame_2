#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	TriggerJumpUp::TriggerJumpUp()
	{

	}

	TriggerJumpUp::~TriggerJumpUp()
	{

	}

	void TriggerJumpUp::OnEnter()
	{

	}

	void TriggerJumpUp::OnUpdate()
	{
		RB::Players::iPlayer* player = _state->GetOwnerPlayer();
		RB::Players::PlayerID playerID = player->GetPlayerID();

		olc::HWButton jump = RB::Input::CurrentInputController::GetController()->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			_state->QueueNextState(new RB::P0_States::P0_JumpUp());

			return;
		}
	}
}