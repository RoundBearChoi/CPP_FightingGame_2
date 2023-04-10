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
}