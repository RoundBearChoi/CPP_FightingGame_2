#include "TriggerMoveForward.h"

namespace RB::PlayerStateComponents
{
	void TriggerMoveForward::OnEnter()
	{
		_moveForwardDetector.Init(_state->GetOwnerPlayer());
	}

	void TriggerMoveForward::OnUpdate()
	{
		_moveForwardDetector.OnUpdate();

		if (_moveForwardDetector.MoveForward())
		{
			//std::cout << "player " << (int)_state->GetOwnerPlayer()->GetPlayerID() << " is moving forward" << std::endl;

			_state->QueueNextState(new RB::P0_States::P0_MoveForward());
		}
	}
}