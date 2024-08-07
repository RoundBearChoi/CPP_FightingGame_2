#include "MoveUpOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveUpOnJump::MoveUpOnJump(unsigned int totalFrames, float multiplier, RB::States::iState* nextState)
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
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		//get vertical up
		unsigned int frame = _state->GetCumulatedFixedUpdates();
		float percentage = (float)frame / (float)_totalFrames;
		float amount = RB::Ease::EaseOutSine(percentage);
		float result = amount * _multiplier;

		//apply vertical up
		if (_state->GetCumulatedFixedUpdates() < _totalFrames)
		{
			player->Move(RB::Vector2{ 0.0f, -result });
		}

		//next state
		else
		{
			RB::States::iStateMachine* machine = player->GetStateMachine();

			machine->QueueNextState(_vecNextStates[0]);
		}
	}
}
