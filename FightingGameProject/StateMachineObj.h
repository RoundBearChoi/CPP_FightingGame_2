#pragma once
#include <iostream>
#include "iStateMachine.h"
#include "iState.h"

using namespace std;

namespace RB::States
{
	class StateMachineObj : public iStateMachine
	{
	protected:
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;

	public:
		StateMachineObj();
		virtual ~StateMachineObj() override;

		virtual void Init(iState* state) override;
		virtual void OnUpdate() override;
		virtual void OnFixedUpdate() override;
		virtual void QueueNextState(iState* state) override;
		virtual void DestroyCurrentState();
	};
}