#include "StateMachineBase.h"

namespace RB::States
{
	StateMachineBase::StateMachineBase()
	{
		std::cout << "constructing StateMachineBase" << std::endl;
	}

	StateMachineBase::~StateMachineBase()
	{
		std::cout << "destroying StateMachineBase" << std::endl;

		_DestroyCurrentState();
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
		if (!_makeTransition)
		{
			_currentState->OnUpdate();
		}

		_MakeTransition();
	}

	void StateMachineBase::OnFixedUpdate()
	{
		if (!_makeTransition)
		{
			_currentState->OnFixedUpdate();
			_currentState->AddCumulatedFixedUpdate();
		}
	}

	void StateMachineBase::QueueNextState(iState* state)
	{
		if (state == nullptr)
		{
			return;
		}

		if (_makeTransition == false)
		{
			_nextState = state;

			_makeTransition = true;
		}
		else
		{
			delete state;
		}
	}

	void StateMachineBase::SetID(int ID)
	{
		_stateMachineID = ID;
	}

	int StateMachineBase::GetID()
	{
		return _stateMachineID;
	}

	void StateMachineBase::_DestroyCurrentState()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
		}
	}

	void StateMachineBase::_MakeTransition()
	{
		if (_makeTransition)
		{
			_DestroyCurrentState();

			_currentState = _nextState;

			_currentState->SetStateMachine(this);
			_currentState->OnEnter();

			_nextState = nullptr;

			_makeTransition = false;
		}
	}
}