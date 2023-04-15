#include "TriggerMoveBack.h"

namespace RB::PlayerStateComponents
{
	TriggerMoveBack::TriggerMoveBack()
	{

	}

	TriggerMoveBack::~TriggerMoveBack()
	{

	}

	void TriggerMoveBack::OnEnter()
	{
		_moveBackDetector.Init(_state->GetOwnerPlayer());
	}

	void TriggerMoveBack::OnUpdate()
	{
		_moveBackDetector.OnUpdate();

		if (_moveBackDetector.MoveBack())
		{
			//std::cout << "player " << (int)_state->GetOwnerPlayer()->GetPlayerID() << " is moving back" << std::endl;

			_state->QueueNextState(new RB::PlayerStates::MoveBack());
		}
	}
}