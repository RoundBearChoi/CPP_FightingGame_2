#include "FixWincingStatusDuringState.h"

namespace RB::PlayerStateComponents
{
	FixWincingStatusDuringState::FixWincingStatusDuringState(bool fix)
	{
		_fix = fix;
	}

	void FixWincingStatusDuringState::OnEnter()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		_player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_player->SetWincingStatus(_fix);
	}

	void FixWincingStatusDuringState::OnExit()
	{
		_player->SetWincingStatus(!_fix);
	}
}
