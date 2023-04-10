#include "StateBase.h"

namespace RB::States
{
	void StateBase::SetStateMachine(iStateMachine* stateMachine)
	{
		_stateMachine = stateMachine;
	}
	
	void StateBase::QueueNextState(iState* nextState)
	{
		_stateMachine->QueueNextState(nextState);
	}

	void StateBase::AddCumulatedFixedUpdate()
	{
		_cumulatedFixedUpdates++;
	}

	unsigned int StateBase::GetCumulatedFixedUpdates()
	{
		return _cumulatedFixedUpdates;
	}

	RB::Players::iPlayer* StateBase::GetOwnerPlayer()
	{
		RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		return player;
	}
}