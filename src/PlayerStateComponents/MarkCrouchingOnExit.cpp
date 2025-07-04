#include "MarkCrouchingOnExit.h"

namespace RB::PlayerStateComponents
{
	MarkCrouchingOnExit::MarkCrouchingOnExit(bool crouching)
	{
		_crouching = crouching;
	}

	void MarkCrouchingOnExit::OnExit()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->MarkCrouching(_crouching);
	}
}
