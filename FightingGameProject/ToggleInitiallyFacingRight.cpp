#include "ToggleInitiallyFacingRight.h"

namespace RB::PlayerStateComponents
{
	ToggleInitiallyFacingRight::ToggleInitiallyFacingRight(bool isFacingRight)
	{
		_facingRight = isFacingRight;
	}

	void ToggleInitiallyFacingRight::OnEnter()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->InitiallyFacingRight(_facingRight);

		//std::cout << "player " << player->GetPlayerID_int() << " initially facing right: " << _facingRight << std::endl;
	}
}