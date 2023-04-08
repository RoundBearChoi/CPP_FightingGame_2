#include "StateMachineObj.h"

namespace RB::StateMachine
{
	StateMachineObj::~StateMachineObj()
	{
		DestroyCurrentState();
	}

	void StateMachineObj::DestroyCurrentState()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
		}
	}

	void StateMachineObj::QueueNextState(iState* state)
	{
		DestroyCurrentState();

		_currentState = _nextState;

		_currentState->OnEnter();

		_nextState = nullptr;
	}
}