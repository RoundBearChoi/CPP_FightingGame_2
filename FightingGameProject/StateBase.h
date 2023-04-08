#pragma once
#include <iostream>
#include "iState.h"

using namespace std;

namespace RB::States
{
	class StateBase : public iState
	{
	protected:
		iStateMachine* _stateMachine = nullptr;

	public:
		virtual ~StateBase() override;

		virtual void SetStateMachine(iStateMachine* stateMachine) override;
		virtual void QueueNextState(iState* nextState) override;

		virtual void OnEnter() override {}
		virtual void OnExit() override {}
		virtual void OnUpdate() override {}
		virtual void OnFixedUpdate() override {}
	};
}