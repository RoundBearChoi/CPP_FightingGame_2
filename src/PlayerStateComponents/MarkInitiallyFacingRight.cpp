#include "MarkInitiallyFacingRight.h"

namespace RB::PlayerStateComponents
{
	void MarkInitiallyFacingRight::OnEnter()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->InitiallyFacingRight(player->OtherPlayerIsOnRightSide());

		//std::cout << "player " << player->GetPLAYER_TYPE_int() << " initially facing right: " << _facingRight << std::endl;
	}
}
