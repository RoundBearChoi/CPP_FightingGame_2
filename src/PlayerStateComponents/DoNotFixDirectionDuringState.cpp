#include "DoNotFixDirectionDuringState.h"

namespace RB::PlayerStateComponents
{
	void DoNotFixDirectionDuringState::OnEnter()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		_player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_player->FixDirDuringState(false);
	}

	void DoNotFixDirectionDuringState::OnExit()
	{
		_player->FixDirDuringState(true);
	}
}
