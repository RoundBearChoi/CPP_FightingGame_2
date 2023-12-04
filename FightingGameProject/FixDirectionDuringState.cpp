#include "FixDirectionDuringState.h"

namespace RB::PlayerStateComponents
{
	FixDirectionDuringState::FixDirectionDuringState(bool fix)
	{
		_fix = fix;
	}

	void FixDirectionDuringState::OnEnter()
	{
		_player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_player->FixDirDuringState(_fix);
	}

	void FixDirectionDuringState::OnExit()
	{
		_player->FixDirDuringState(!_fix);
	}
}