#include "TriggerMoveBack.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveBack::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
		RB::Players::iPlayer* owner = pc->GetPlayerOnStateMachineID(_state->GetStateMachine()->GetID());

		_moveBackDetector.Init(owner);
	}

	void TriggerMoveBack::OnUpdate()
	{
		_moveBackDetector.OnUpdate();

		if (_moveBackDetector.MoveBack())
		{
			_state->QueueNextState(new RB::P0_States::P0_MoveBack());
		}
	}
}