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
		float_t prog = 1.0f - ((float_t)_state->GetCumulatedFixedUpdates() / (float_t)_totalFrames);
		float_t multiplier = 3.0f;
		float_t amount = RB::Equations::Ease::EaseOutQuint(prog * multiplier);

		//apply
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		olc::vf2d momentum = player->GetAirMomentum();
		player->SetAirMomentum(olc::vf2d{ momentum.x, -amount });
		player->Move(olc::vf2d{ 0.0f, -amount });

		//next state
		if (_state->GetCumulatedFixedUpdates() >= _totalFrames)
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_FallDown());
		}
	}
}