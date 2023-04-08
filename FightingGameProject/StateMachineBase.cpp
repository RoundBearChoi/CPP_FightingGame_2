#include "StateMachineBase.h"

namespace RB::States
{
	StateMachineBase::StateMachineBase()
	{
		cout << "constructing StateMachineBase" << endl;
	}

	StateMachineBase::~StateMachineBase()
	{
		cout << "destroying StateMachineBase" << endl;

		DestroyCurrentState();
	}

	void StateMachineBase::Init(iState* state)
	{
		if (state != nullptr)
		{
			_currentState = state;
			_currentState->SetStateMachine(this);
			_currentState->OnEnter();
		}
	}

	void StateMachineBase::OnUpdate()
	{
		_currentState->OnUpdate();
	}

	void StateMachineBase::OnFixedUpdate()
	{
		_currentState->OnFixedUpdate();
	}

	void StateMachineBase::QueueNextState(iState* state)
	{
		DestroyCurrentState();

		_currentState = _nextState;

		_currentState->SetStateMachine(this);
		_currentState->OnEnter();

		_nextState = nullptr;
	}

	void StateMachineBase::DestroyCurrentState()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
		}
	}
}