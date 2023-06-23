#include "TriggerMoveBack.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveBack::OnEnter()
	{
		_moveBackDetector.SetStateMachineID(_state->GetStateMachineID());
	}

	void TriggerMoveBack::OnUpdate()
	{
		//_getter_playerController.OnUpdate();

		//if (_getter_playerController.GetController() == nullptr)
		//{
		//	return;
		//}

		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID()); //_getter_playerController.GetController()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		_moveBackDetector.OnUpdate();

		if (_moveBackDetector.MoveBack())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveBack());
		}
	}
}