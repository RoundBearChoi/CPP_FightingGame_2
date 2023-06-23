#include "TriggerMoveForward.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveForward::OnEnter()
	{
		_moveForwardDetector.SetStateMachineID(_state->GetStateMachineID());
	}

	void TriggerMoveForward::OnUpdate()
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

		_moveForwardDetector.OnUpdate();

		if (_moveForwardDetector.MoveForward())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveForward());
		}
	}
}