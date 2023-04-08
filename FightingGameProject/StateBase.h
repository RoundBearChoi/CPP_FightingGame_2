#pragma once
#include <iostream>
#include "iState.h"
#include "iStateMachine.h"

using namespace std;


namespace RB::StateMachine
{
	class StateBase : public iState
	{
	protected:
		//RB::StateMachine::iStateMachine* _stateMachine = nullptr;

	public:
		virtual ~StateBase() override;

		//virtual void SetStateMachine(RB::StateMachine::iStateMachine* stateMachine) override {};
		virtual void QueueNextState(iState* nextState) override;

		virtual void OnEnter() override {}
		virtual void OnExit() override {}
		virtual void OnUpdate() override {}
		virtual void OnFixedUpdate() override {}
	};
}