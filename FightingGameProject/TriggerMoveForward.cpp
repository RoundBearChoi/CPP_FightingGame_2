#include "TriggerMoveForward.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveForward::OnEnter()
	{
		_moveForwardDetector.SetStateMachineID(_state->GetStateMachineID());
	}

	void TriggerMoveForward::OnUpdate()
	{
		//_getter_playerController.OnUpdate();
		//
		//if (_getter_playerController.GetController() == nullptr)
		//{
		//	return;
		//}

		if (RB::Players::PlayerController::PTR == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PlayerController::PTR->GetPlayerOnStateMachineID(_state->GetStateMachineID()); //_getter_playerController.GetController()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

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