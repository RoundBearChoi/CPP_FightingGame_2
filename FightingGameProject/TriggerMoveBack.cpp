#include "TriggerMoveBack.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveBack::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_moveBackDetector.Init(_ownerPlayer);
	}

	void TriggerMoveBack::OnUpdate()
	{
		_moveBackDetector.OnUpdate();

		if (_moveBackDetector.MoveBack())
		{
			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();

			machine->QueueNextState(new RB::P0_States::P0_MoveBack());
		}
	}
}