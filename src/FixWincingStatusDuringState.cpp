#include "FixWincingStatusDuringState.h"

namespace RB::PlayerStateComponents
{
	FixWincingStatusDuringState::FixWincingStatusDuringState(bool fix)
	{
		_fix = fix;
	}

	void FixWincingStatusDuringState::OnEnter()
	{
		_player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_player->SetWincingStatus(_fix);
	}

	void FixWincingStatusDuringState::OnExit()
	{
		_player->SetWincingStatus(!_fix);
	}
}
