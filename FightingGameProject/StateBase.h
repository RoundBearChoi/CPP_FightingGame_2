#pragma once
#include "iState.h"

//class iStateMachine;

namespace RB::StateMachine
{
	class StateBase : public iState
	{
	protected:
		iStateMachine* _stateMachine;

	public:
		virtual ~StateBase() override {}

		//virtual void SetStateMachine(iStateMachine* stateMachine) override;
		virtual void QueueNextState(iState* nextState) override;

		virtual void OnEnter() override {}
		virtual void OnExit() override {}
		virtual void OnUpdate() override {}
		virtual void OnFixedUpdate() override {}
	};
}