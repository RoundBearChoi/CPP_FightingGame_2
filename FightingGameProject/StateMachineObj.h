#pragma once
#include "iStateMachine.h"
#include "iState.h"

namespace RB::StateMachine
{
	class StateMachineObj : iStateMachine
	{
	protected:
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;

	public:
		virtual ~StateMachineObj() override;

		virtual void DestroyCurrentState();
		virtual void QueueNextState(iState* state);
	};
}