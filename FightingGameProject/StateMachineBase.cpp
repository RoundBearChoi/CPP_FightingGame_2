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
		_currentState = state;
		_currentState->SetStateMachineID(_stateMachineID);
		_currentState->OnEnter();
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
			_currentState->SetTransitionStatus(true);

			_makeTransition = true;

			_nextState = state;
		}
		else
		{
			delete state;
		}
	}

	void StateMachineBase::SetID(size_t ID)
	{
		_stateMachineID = ID;
	}

	size_t StateMachineBase::GetID()
	{
		return _stateMachineID;
	}

	iState* StateMachineBase::GetCurrentState()
	{
		return _currentState;
	}

	bool StateMachineBase::IsTransitioning()
	{
		return _makeTransition;
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

			_makeTransition = false;
			_nextState = nullptr;

			_currentState->SetStateMachineID(_stateMachineID);
			_currentState->OnEnter();
		}
	}
}