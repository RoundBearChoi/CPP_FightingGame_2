#include "TriggerMoveBack.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveBack::OnEnter()
	{

	}

	void TriggerMoveBack::OnUpdate()
	{
		_getter_playerController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_moveBackDetector.SetOwnerPlayer(player);
		_moveBackDetector.OnUpdate();

		if (_moveBackDetector.MoveBack())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveBack());
		}
	}
}