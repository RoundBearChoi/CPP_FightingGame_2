#include "StateMachineBase.h"

namespace RB::States
{
	unsigned int StateMachineBase::stateMachinesCreated = 0;

	StateMachineBase::StateMachineBase()
	{
		stateMachinesCreated++;
		_stateMachineID = stateMachinesCreated;
	}

	StateMachineBase::~StateMachineBase()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
			_currentState = nullptr;
		}
	}

	void StateMachineBase::Init(iState* state)
	{
		_currentState = state;
		_InitState(state);
	}

	void StateMachineBase::OnUpdate()
	{
		if (!_currentState->IsTransitioning())
		{
			_currentState->OnUpdate();
		}
	}

	void StateMachineBase::OnFixedUpdate()
	{
		if (!_currentState->IsTransitioning())
		{
			_currentState->OnFixedUpdate();
			_currentState->AddCumulatedFixedUpdate();
		}

		_MakeTransition();
	}

	bool StateMachineBase::QueueNextState(iState* state)
	{
		if (state == nullptr)
		{
			return false;
		}

		if (!_currentState->IsTransitioning())
		{
			_currentState->SetIsTransitioning(true);

			_nextState = state;
		}

		return true;
	}

	void StateMachineBase::ClearQueuedStates()
	{
		//all past player states will be deleted by PlayerState::ErasePreviousStates()
		_nextState = nullptr;

		//reset status and queue
		_currentState->SetIsTransitioning(false);
	}

	unsigned int StateMachineBase::GetID()
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

	void StateMachineBase::_MakeTransition()
	{
		if (_currentState->IsTransitioning())
		{
			//exit current state first
			_currentState->OnExit();

			//enter next state
			_InitState(_nextState);

			_currentState = _nextState;
			_nextState = nullptr;

			//del prev states
			_currentState->ErasePreviousStates();
		}
	}

	void StateMachineBase::_InitState(iState* state)
	{
		state->SetStateMachineID(_stateMachineID);
		state->LogStateEnter();
		state->OnEnter();
		state->SetStateMachineIDs_Recursively();
	}
}
