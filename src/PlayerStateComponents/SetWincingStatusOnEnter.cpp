#include "SetWincingStatusOnEnter.h"

namespace RB::PlayerStateComponents
{
	SetWincingStatusOnEnter::SetWincingStatusOnEnter(bool fix)
	{
		_fix = fix;
	}

	void SetWincingStatusOnEnter::OnEnter()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		_player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_player->SetWincingStatus(_fix);
	}

	void SetWincingStatusOnEnter::OnExit()
	{
		_player->SetWincingStatus(!_fix);
	}
}
