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

		_ExitAndDestroyCurrentState();
	}

	void StateMachineBase::Init(iState* state)
	{
		SetID(RB::States::ActiveStateMachines::GetID());
		RB::States::ActiveStateMachines::AddStateMachine(this);

		_currentState = state;
		_currentState->SetStateMachineID(_stateMachineID);
		_currentState->OnEnter();
	}

	void StateMachineBase::OnUpdate()
	{
		if (!_currentState->IsTransitioning())
		{
			_currentState->OnUpdate();
		}

		_MakeTransition();
	}

	void StateMachineBase::OnFixedUpdate()
	{
		if (!_currentState->IsTransitioning())
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

		if (!_currentState->IsTransitioning())
		{
			_currentState->SetTransitionStatus(true);

			_nextState = state;
		}
		else
		{
			delete state;
		}
	}

	void StateMachineBase::OverrideNextState(RB::States::iState* state)
	{
		if (_nextState != nullptr)
		{
			delete _nextState;
		}

		_currentState->SetTransitionStatus(true);

		_nextState = state;
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
		return _currentState->IsTransitioning();
	}

	void StateMachineBase::_ExitAndDestroyCurrentState()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
		}
	}

	void StateMachineBase::_MakeTransition()
	{
		if (_currentState->IsTransitioning())
		{
			_ExitAndDestroyCurrentState();

			_currentState = _nextState;

			_nextState = nullptr;

			_currentState->SetStateMachineID(_stateMachineID);
			_currentState->OnEnter();
		}
	}
}