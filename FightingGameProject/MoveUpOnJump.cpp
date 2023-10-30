#include "MoveUpOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveUpOnJump::MoveUpOnJump(size_t totalFrames)
	{
		_totalFrames = totalFrames;
	}

	void MoveUpOnJump::OnEnter()
	{

	}

	void MoveUpOnJump::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		//get vertical up
		float_t percentage = (float_t)_state->GetCumulatedFixedUpdates() / (float_t)_totalFrames;
		float_t multiplier = 28.0f;
		float_t amount = RB::EaseEquations::Ease::EaseOutQuad(percentage);
		float_t result = amount * multiplier;

		//apply
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		olc::vf2d momentum = player->GetAirMomentum();
		player->SetAirMomentum(olc::vf2d{ momentum.x, -result });
		player->Move(olc::vf2d{ 0.0f, -result });

		//next state
		if (_state->GetCumulatedFixedUpdates() >= _totalFrames)
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_FallDown());
		}
	}
}