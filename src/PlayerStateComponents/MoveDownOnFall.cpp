#include "MoveDownOnFall.h"

namespace RB::PlayerStateComponents
{
	// total frames to reach max fall speed
	MoveDownOnFall::MoveDownOnFall(unsigned int totalFrames, float multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	MoveDownOnFall::~MoveDownOnFall()
	{

	}

	void MoveDownOnFall::OnEnter()
	{

	}

	void MoveDownOnFall::OnFixedUpdate()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		unsigned int frame = _state->GetCumulatedFixedUpdates();

		//get vertical down
		float t = (float)frame / (float)_totalFrames;

		if (t >= 1.0f)
		{
			t = 1.0f;
		}

		float amount = 1.0f - RB::Ease::EaseOutSine(t);
		float result = amount * _multiplier;

		float y = player->GetPosition().y;

		//do not fall below ground level
		if (y + result >= 0.0f)
		{
			player->SetPosition({ player->GetPosition().x, 0.0f });
		}

		//keep falling
		else
		{
			player->Move(RB::Vector2{ 0.0f, result });
		}
	}
}
