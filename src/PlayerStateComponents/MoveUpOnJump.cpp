#include "MoveUpOnJump.h"

namespace RB::PlayerStateComponents
{
	MoveUpOnJump::MoveUpOnJump(unsigned int totalFrames, float multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
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

		if (percentage >= 1.0f)
		{
			percentage = 1.0f;
		}

		float amount = RB::Ease::EaseOutSine(percentage);
		float result = amount * _multiplier;
		
		player->Move(RB::Vector2{ 0.0f, -result });
	}
}
