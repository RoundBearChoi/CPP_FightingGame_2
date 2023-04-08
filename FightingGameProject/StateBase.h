#pragma once
#include <iostream>
#include "iState.h"
#include "iStateMachine.h"

using namespace std;

namespace RB::States
{
	class StateBase : public iState
	{
	protected:
		iStateMachine* _stateMachine = nullptr;

	public:
		virtual ~StateBase() {};

		virtual void SetStateMachine(iStateMachine* stateMachine);
		virtual void QueueNextState(iState* nextState);

		virtual void OnEnter() {}
		virtual void OnExit() {}
		virtual void OnUpdate() {}
		virtual void OnFixedUpdate() {}
	};
}