#include "DoNotFixDirectionDuringState.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	void DoNotFixDirectionDuringState::OnEnter()
	{
		_player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_player->FixDirDuringState(false);
	}

	void DoNotFixDirectionDuringState::OnExit()
	{
		_player->FixDirDuringState(true);
	}
}