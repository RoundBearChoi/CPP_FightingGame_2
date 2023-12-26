#include "StateMachineBase.h"

namespace RB::States
{
	size_t StateMachineBase::stateMachinesCreated = 0;

	StateMachineBase::StateMachineBase()
	{
		stateMachinesCreated++;
		_stateMachineID = stateMachinesCreated;

		std::cout << "constructing StateMachineBase" << std::endl;
	}

	StateMachineBase::~StateMachineBase()
	{
		std::cout << "destroying StateMachineBase" << std::endl;

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
			_currentState->SetIsTransitioning(true);

			_nextState = state;
			_nextState->SetIsInQueue(true);
		}
		//else
		//{
		//	delete state;
		//	state = nullptr;
		//}
	}

	void StateMachineBase::OverrideNextState(RB::States::iState* state)
	{
		if (_nextState != nullptr)
		{
			delete _nextState;
			_nextState = nullptr;
		}

		_currentState->SetIsTransitioning(false);

		QueueNextState(state);

		//_currentState->SetIsTransitioning(true);
		//
		//_nextState = state;
		//_nextState->SetIsInQueue(true);
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

	void StateMachineBase::_MakeTransition()
	{
		if (_currentState->IsTransitioning())
		{
			//exit current state first
			_currentState->OnExit();

			//enter next state
			_nextState->SetStateMachineID(_stateMachineID);
			_nextState->OnEnter();

			//clean up last so statecomponents don't delete next state
			delete _currentState;
			_currentState = nullptr;

			_currentState = _nextState;
			_nextState = nullptr;
		}
	}
}