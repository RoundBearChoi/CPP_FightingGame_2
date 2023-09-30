#include "TriggerIdle.h"

namespace RB::PlayerStateComponents
{
	TriggerIdle::TriggerIdle(int32_t fixedUpdateOnCount)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
	}
	void TriggerIdle::OnEnter()
	{

	}

	void TriggerIdle::OnUpdate()
	{

	}

	void TriggerIdle::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->GetStateMachine()->QueueNextState(new RB::PlayerStates::P0_Idle());
	}
}