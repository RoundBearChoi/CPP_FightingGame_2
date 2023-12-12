#include "MoveDownOnFall.h"

namespace RB::PlayerStateComponents
{
	/// <summary>
	/// total frames to reach max fall speed
	/// </summary>
	MoveDownOnFall::MoveDownOnFall(size_t totalFrames, float_t multiplier, RB::States::iState* nextState)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
		//_nextState = nextState;
		_vecNextStates.push_back(nextState);
	}

	MoveDownOnFall::~MoveDownOnFall()
	{

	}

	void MoveDownOnFall::OnEnter()
	{

	}

	void MoveDownOnFall::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		size_t frame = _state->GetCumulatedFixedUpdates();

		//get vertical down
		float_t t = (float_t)frame / (float_t)_totalFrames;

		if (t >= 1.0f)
		{
			t = 1.0f;
		}

		float_t amount = 1.0f - RB::EaseEquations::Ease::EaseOutSine(t);
		float_t result = amount * _multiplier;

		int32_t y = player->GetPosition().y;

		//transition to idle 1 frame before hitting ground
		if ((float_t)y + result >= 0.0f)
		{
			player->SetPosition({ player->GetPosition().x, 0 });

			RB::States::iStateMachine* machine = player->GetStateMachine();
			
			//machine->QueueNextState(_nextState);
			machine->QueueNextState(_vecNextStates[0]);
		}

		//keep falling
		else
		{
			player->Move(olc::vf2d{ 0.0f, result });
		}
	}
}