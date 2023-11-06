#include "MoveUpOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveUpOnJump::MoveUpOnJump(size_t totalFrames, float_t multiplier, RB::PlayerStates::PlayerState* nextState)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
		_nextState = nextState;
	}

	MoveUpOnJump::~MoveUpOnJump()
	{
		if (!_state->IsTransitioning())
		{
			delete _nextState;
			_nextState = nullptr;
		}
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

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//apply vertical up
		if (_state->GetCumulatedFixedUpdates() < _totalFrames)
		{
			player->Move(olc::vf2d{ 0.0f, -result });
		}

		//next state
		else
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();

			if (_nextState != nullptr)
			{
				machine->QueueNextState(_nextState);
			}
		}
	}
}