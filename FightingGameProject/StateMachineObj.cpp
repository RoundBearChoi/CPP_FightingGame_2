#include "StateMachineObj.h"

namespace RB::States
{
	StateMachineObj::StateMachineObj()
	{
		cout << "constructing StateMachineObj" << endl;
	}

	StateMachineObj::~StateMachineObj()
	{
		cout << "destroying StateMachineObj" << endl;

		DestroyCurrentState();
	}

	void StateMachineObj::Init(iState* state)
	{
		if (state != nullptr)
		{
			_currentState = state;
			_currentState->OnEnter();
		}
	}

	void StateMachineObj::QueueNextState(iState* state)
	{
		DestroyCurrentState();

		_currentState = _nextState;

		_currentState->OnEnter();

		_nextState = nullptr;
	}

	void StateMachineObj::DestroyCurrentState()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
		}
	}
}