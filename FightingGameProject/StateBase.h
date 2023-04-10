#pragma once
#include <iostream>
#include "iState.h"
#include "iStateMachine.h"

namespace RB::States
{
	class StateBase : public iState
	{
	protected:
		iStateMachine* _stateMachine = nullptr;
		unsigned int _cumulatedFixedUpdates = 0;

	public:
		virtual ~StateBase() {};

		virtual void SetStateMachine(iStateMachine* stateMachine);
		virtual void QueueNextState(iState* nextState);
		virtual void AddCumulatedFixedUpdate();
		virtual unsigned int GetCumulatedFixedUpdates();

	public:
		virtual void OnEnter() {}
		virtual void OnExit() {}
		virtual void OnUpdate() {}
		virtual void OnFixedUpdate() {}
	};
}