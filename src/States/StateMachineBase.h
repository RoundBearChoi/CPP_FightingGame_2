#pragma once

#include "iStateMachine.h"
#include "iState.h"

namespace RB::States
{
	class StateMachineBase : public iStateMachine
	{
	public:
		static unsigned int stateMachinesCreated;

	public:
		StateMachineBase();
		virtual ~StateMachineBase() override;

	public:
		virtual void Init(iState* state) override;
		virtual void OnUpdate() override;
		virtual void OnFixedUpdate() override;

	public:
		virtual bool QueueNextState(iState* state) override;
		virtual void ClearQueuedStates() override;
		virtual unsigned int GetID() override;
		virtual iState* GetCurrentState() override;
		virtual bool IsTransitioning() override;

	protected:
		virtual void _MakeTransition() override;

	private:
		void _InitState(iState* state);

		unsigned int _stateMachineID = 0;
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;
	};
}
