#pragma once
#include "iStateMachine.h"
#include "iState.h"

namespace RB::StateMachine
{
	class StateBase : public iState
	{
	private:
		iStateMachine* _stateMachine;

	public:
		virtual void OnEnter() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void QueueNextState(iState* nextState) override;
	};
}