#include "FixSpecialMoveStatusDuringState.h"

namespace RB::PlayerStateComponents
{
	FixSpecialMoveStatusDuringState::FixSpecialMoveStatusDuringState(bool fix)
	{
		_fix = fix;
	}

	void FixSpecialMoveStatusDuringState::OnEnter()
	{
		_player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		// should be fixed to set special move status..
		//_player->SetWincingStatus(_fix);
	}

	void FixSpecialMoveStatusDuringState::OnExit()
	{
		//_player->SetWincingStatus(!_fix);
	}
}
