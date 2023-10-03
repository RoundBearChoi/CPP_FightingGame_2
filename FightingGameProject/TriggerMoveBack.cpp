#include "TriggerMoveBack.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveBack::OnEnter()
	{
		_moveBackOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void TriggerMoveBack::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		_moveBackOnPress.OnUpdate();

		if (_moveBackOnPress.ProcMoveBack())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveBack());
		}
	}
}