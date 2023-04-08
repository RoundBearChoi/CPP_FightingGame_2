#pragma once
#include <iostream>
#include "iStateMachine.h"
#include "iState.h"

using namespace std;

namespace RB::StateMachine
{
	class StateMachineObj : iStateMachine
	{
	protected:
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;

	public:
		StateMachineObj();
		virtual ~StateMachineObj() override;

		virtual void Init(iState* state) override;
		virtual void QueueNextState(iState* state) override;
		virtual void DestroyCurrentState();
	};
}