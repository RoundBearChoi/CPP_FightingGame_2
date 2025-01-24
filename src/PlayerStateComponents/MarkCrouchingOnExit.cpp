#include "MarkCrouchingOnExit.h"

namespace RB::PlayerStateComponents
{
	MarkCrouchingOnExit::MarkCrouchingOnExit(bool crouching)
	{
		_crouching = crouching;
	}

	void MarkCrouchingOnExit::OnExit()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		std::cout << std::endl;
		//std::cout << "player " << player->GetPlayerID_int() << " crouching: " << _crouching << std::endl;

		player->MarkCrouching(_crouching);
	}
}