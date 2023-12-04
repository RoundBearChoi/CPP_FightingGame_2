#include "TriggerIdleOnFixedUpdateCount.h"

namespace RB::PlayerStateComponents
{
	TriggerIdleOnFixedUpdateCount::TriggerIdleOnFixedUpdateCount(int32_t fixedUpdateOnCount)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
	}
	void TriggerIdleOnFixedUpdateCount::OnEnter()
	{

	}

	void TriggerIdleOnFixedUpdateCount::OnUpdate()
	{

	}

	void TriggerIdleOnFixedUpdateCount::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->GetStateMachine()->QueueNextState(new RB::PlayerStates::P0_Idle());
	}
}