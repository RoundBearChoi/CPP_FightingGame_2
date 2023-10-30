#include "MoveUpOnJump.h"

namespace RB::PlayerStateComponents
{
	void MoveUpOnJump::OnEnter()
	{

	}

	void MoveUpOnJump::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		olc::vf2d momentum = player->GetAirMomentum();

		if (momentum.y < 0.5f)
		{
			player->SetAirMomentum(olc::vf2d{ momentum.x, 0.0f });

			RB::States::iStateMachine* machine = player->GetStateMachine();

			machine->QueueNextState(new RB::PlayerStates::P0_FallDown());
		}
		else
		{
			float y = player->GetAirMomentum().y;

			player->Move(olc::vf2d{ 0.0f, -y });

			float ySlowAmount = 0.3f;

			player->AddMomentum(olc::vf2d{ 0.0f, -ySlowAmount });
		}
	}
}