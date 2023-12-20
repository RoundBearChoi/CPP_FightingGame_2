#include "MoveUpOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveUpOnJump::MoveUpOnJump(size_t totalFrames, float_t multiplier, RB::States::iState* nextState)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
		_vecNextStates.push_back(nextState);
	}

	MoveUpOnJump::~MoveUpOnJump()
	{

	}

	void MoveUpOnJump::OnEnter()
	{

	}

	void MoveUpOnJump::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		//get vertical up
		size_t frame = _state->GetCumulatedFixedUpdates();
		float_t percentage = (float_t)frame / (float_t)_totalFrames;
		float_t amount = RB::EaseEquations::Ease::EaseOutSine(percentage);
		float_t result = amount * _multiplier;

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::CharacterType characterType = player->GetCharacterType();

		//apply vertical up
		if (_state->GetCumulatedFixedUpdates() < _totalFrames)
		{
			player->Move(olc::vf2d{ 0.0f, -result });
		}

		//next state
		else
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();

			machine->QueueNextState(_vecNextStates[0]);
		}
	}
}