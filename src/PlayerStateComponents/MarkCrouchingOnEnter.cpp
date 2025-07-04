#include "MarkCrouchingOnEnter.h"

namespace RB::PlayerStateComponents
{
	MarkCrouchingOnEnter::MarkCrouchingOnEnter(bool crouching)
	{
		_crouching = crouching;
	}

	void MarkCrouchingOnEnter::OnEnter()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->MarkCrouching(_crouching);
	}
}
