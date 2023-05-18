#include "TriggerMoveForward.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveForward::OnEnter()
	{

	}

	void TriggerMoveForward::OnUpdate()
	{
		_getter_playerController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		_moveForwardDetector.SetOwnerPlayer(player);
		_moveForwardDetector.OnUpdate();

		if (_moveForwardDetector.MoveForward())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveForward());
		}
	}
}