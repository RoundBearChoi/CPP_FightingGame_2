#include "MarkInitiallyFacingRight.h"

namespace RB::PlayerStateComponents
{
	void MarkInitiallyFacingRight::OnEnter()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->InitiallyFacingRight(player->OtherPlayerIsOnRightSide());

		//std::cout << "player " << player->GetPlayerID_int() << " initially facing right: " << _facingRight << std::endl;
	}
}