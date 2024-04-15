#include "FixSpecialMoveStatusDuringState.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	FixSpecialMoveStatusDuringState::FixSpecialMoveStatusDuringState(bool fix)
	{
		_fix = fix;
	}

	void FixSpecialMoveStatusDuringState::OnEnter()
	{
		_player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_player->SetWincingStatus(_fix);
	}

	void FixSpecialMoveStatusDuringState::OnExit()
	{
		_player->SetWincingStatus(!_fix);
	}
}