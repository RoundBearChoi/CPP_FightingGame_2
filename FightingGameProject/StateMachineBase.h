#pragma once
#include <iostream>
#include "iStateMachine.h"
#include "iState.h"

using namespace std;

namespace RB::States
{
	class StateMachineBase : public iStateMachine
	{
	public:
		StateMachineBase();
		virtual ~StateMachineBase() override;

		virtual void Init(iState* state) override;
		virtual void OnUpdate() override;
		virtual void OnFixedUpdate() override;
		virtual void QueueNextState(iState* state) override;

	protected:
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;
		bool _makeTransition = false;

		virtual void _DestroyCurrentState();
		virtual void _MakeTransition() override;
	};
}