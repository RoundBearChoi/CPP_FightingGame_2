#include "MarkInitiallyFacingRight.h"

namespace RB::PlayerStateComponents
{
	void MarkInitiallyFacingRight::OnEnter()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->InitiallyFacingRight(player->OtherPlayerIsOnRightSide());

		//std::cout << "player " << player->GetPlayerID_int() << " initially facing right: " << _facingRight << std::endl;
	}
}