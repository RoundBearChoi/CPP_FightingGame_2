#include "MoveUpOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveUpOnJump::MoveUpOnJump(size_t totalFrames, float_t multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
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
		size_t frame = _state->GetCumulatedFixedUpdates();
		float_t percentage = (float_t)frame / (float_t)_totalFrames;
		float_t amount = RB::EaseEquations::Ease::EaseOutSine(percentage);
		float_t result = amount * _multiplier;

		//apply
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		player->Move(olc::vf2d{ 0.0f, -result });

		//next state
		if (_state->GetCumulatedFixedUpdates() >= _totalFrames)
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_FallDown());
		}
	}
}