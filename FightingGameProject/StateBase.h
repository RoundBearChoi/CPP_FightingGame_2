#pragma once
#include "iStateMachine.h"
#include "iState.h"

namespace RB::StateMachine
{
	class StateBase
	{
	protected:
		iStateMachine* _stateMachine;

	public:
		virtual ~StateBase() {}

		virtual void SetStateMachine(iStateMachine* stateMachine);
		virtual void OnEnter() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void QueueNextState(iState* nextState);
	};
}