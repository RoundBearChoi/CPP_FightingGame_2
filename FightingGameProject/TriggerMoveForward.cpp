#include "TriggerMoveForward.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveForward::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_moveForwardDetector.Init(_ownerPlayer);
	}

	void TriggerMoveForward::OnUpdate()
	{
		_moveForwardDetector.OnUpdate();

		if (_moveForwardDetector.MoveForward())
		{
			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();

			machine->QueueNextState(new RB::PlayerStates::P0_MoveForward());
		}
	}
}