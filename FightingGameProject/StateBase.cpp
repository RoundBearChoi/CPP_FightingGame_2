#include "StateBase.h"

namespace RB::StateMachine
{
	void StateBase::QueueNextState(iState* nextState)
	{
		_stateMachine->QueueNextState(nextState);
	}
}