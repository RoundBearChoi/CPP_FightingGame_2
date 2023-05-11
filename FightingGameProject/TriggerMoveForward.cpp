#include "TriggerMoveForward.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveForward::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::Controllers::GetController<RB::Players::PlayerController>();
		RB::Players::iPlayer* owner = pc->GetPlayerOnStateMachineID(_state->GetStateMachine()->GetID());

		_moveForwardDetector.Init(owner);
	}

	void TriggerMoveForward::OnUpdate()
	{
		_moveForwardDetector.OnUpdate();

		if (_moveForwardDetector.MoveForward())
		{
			_state->QueueNextState(new RB::P0_States::P0_MoveForward());
		}
	}
}