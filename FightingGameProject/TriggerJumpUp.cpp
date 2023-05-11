#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{

	}

	void TriggerJumpUp::OnUpdate()
	{
		RB::Players::iPlayer* player = _state->GetOwnerPlayer();
		RB::Players::PlayerID playerID = player->GetPlayerID();

		std::string name = typeid(RB::Input::InputController).name();
		RB::Controllers::iController* inputController = RB::Controllers::CurrentControllers::GetController(std::hash<std::string>{}(name));
		RB::Input::InputController* ic = dynamic_cast<RB::Input::InputController*>(inputController);

		olc::HWButton jump = ic->GetButton(playerID, RB::Input::PlayerInput::JUMP);

		if (jump.bPressed || jump.bHeld)
		{
			_state->QueueNextState(new RB::P0_States::P0_JumpUp());

			return;
		}
	}
}