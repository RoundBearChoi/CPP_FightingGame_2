#include "MoveDownOnFall.h"

namespace RB::PlayerStateComponents
{
	MoveDownOnFall::MoveDownOnFall(size_t totalFrames, float_t multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	void MoveDownOnFall::OnEnter()
	{

	}

	void MoveDownOnFall::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//get vertical down
		float_t percentage = (float_t)_state->GetCumulatedFixedUpdates() / (float_t)_totalFrames;

		if (percentage >= 1.0f)
		{
			percentage = 1.0f;
		}

		float_t amount = 1.0f - RB::EaseEquations::Ease::EaseOutSine(percentage);
		float_t result = amount * _multiplier;

		//prevent going under 0 (temp)
		if (player->GetPosition().y > 0)
		{
			player->SetPosition({ player->GetPosition().x, 0 });

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_Idle());

			return;
		}

		//move down (temp)
		if (_state->GetCumulatedFixedUpdates() < _totalFrames)
		{
			player->Move(olc::vf2d{ 0.0f, result });
		}
		//transition to idle (temp)
		else
		{
			player->SetPosition({ player->GetPosition().x, 0 });

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_Idle());
		}
	}
}