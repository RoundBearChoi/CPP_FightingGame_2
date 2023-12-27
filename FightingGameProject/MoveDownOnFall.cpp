#include "MoveDownOnFall.h"

namespace RB::PlayerStateComponents
{
	/// <summary>
	/// total frames to reach max fall speed
	/// </summary>
	MoveDownOnFall::MoveDownOnFall(unsigned int totalFrames, float multiplier, RB::States::iState* nextState)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
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

		unsigned int frame = _state->GetCumulatedFixedUpdates();

		//get vertical down
		float t = (float)frame / (float)_totalFrames;

		if (t >= 1.0f)
		{
			t = 1.0f;
		}

		float amount = 1.0f - RB::EaseEquations::Ease::EaseOutSine(t);
		float result = amount * _multiplier;

		int y = player->GetPosition().y;

		//transition to idle 1 frame before hitting ground
		if ((float)y + result >= 0.0f)
		{
			player->SetPosition({ player->GetPosition().x, 0 });

			RB::States::iStateMachine* machine = player->GetStateMachine();
			
			machine->QueueNextState(_vecNextStates[0]);
		}

		//keep falling
		else
		{
			player->Move(olc::vf2d{ 0.0f, result });
		}
	}
}