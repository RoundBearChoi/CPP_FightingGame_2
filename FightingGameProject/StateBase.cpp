#include "StateBase.h"

namespace RB::States
{
	StateBase::~StateBase()
	{
		cout << "destroying StateBase" << endl;
	}

	void StateBase::SetStateMachine(iStateMachine* stateMachine)
	{
		_stateMachine = stateMachine;
	}
	
	void StateBase::QueueNextState(iState* nextState)
	{
		_stateMachine->QueueNextState(nextState);
	}
}