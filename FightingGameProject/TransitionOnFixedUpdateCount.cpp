#include "TransitionOnFixedUpdateCount.h"

namespace RB::PlayerStateComponents
{
	TransitionOnFixedUpdateCount::TransitionOnFixedUpdateCount(int32_t fixedUpdateOnCount, RB::States::iState* nextState)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_nextState = nextState;
	}
	void TransitionOnFixedUpdateCount::OnEnter()
	{

	}

	void TransitionOnFixedUpdateCount::OnUpdate()
	{

	}

	void TransitionOnFixedUpdateCount::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		player->GetStateMachine()->QueueNextState(_nextState);
	}
}