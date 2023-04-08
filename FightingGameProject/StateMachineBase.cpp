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

		MakeTransition();
	}

	void StateMachineBase::OnFixedUpdate()
	{
		if (!_makeTransition)
		{
			_currentState->OnFixedUpdate();
		}
	}

	void StateMachineBase::QueueNextState(iState* state)
	{
		if (state != nullptr && _makeTransition == false)
		{
			if (_nextState == nullptr)
			{
				_nextState = state;
				_makeTransition = true;
			}
			else
			{
				delete state;
				_makeTransition = false;
			}
		}
	}

	void StateMachineBase::DestroyCurrentState()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
		}
	}

	void StateMachineBase::MakeTransition()
	{
		if (_makeTransition)
		{
			DestroyCurrentState();

			_currentState = _nextState;

			_currentState->SetStateMachine(this);
			_currentState->OnEnter();

			_nextState = nullptr;

			_makeTransition = false;
		}
	}
}