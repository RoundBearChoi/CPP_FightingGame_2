#include "ToggleInitiallyFacingRight.h"

namespace RB::PlayerStateComponents
{
	void ToggleInitiallyFacingRight::OnEnter()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->InitiallyFacingRight(player->OtherPlayerIsOnRightSide());

		//std::cout << "player " << player->GetPlayerID_int() << " initially facing right: " << _facingRight << std::endl;
	}
}