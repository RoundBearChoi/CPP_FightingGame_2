#pragma once
#include <iostream>
#include "iStateMachine.h"
#include "iState.h"

namespace RB::States
{
	class StateMachineBase : public iStateMachine
	{
	public:
		StateMachineBase();
		virtual ~StateMachineBase() override;

	public:
		virtual void Init(iState* state) override;
		virtual void OnUpdate() override;
		virtual void OnFixedUpdate() override;

	public:
		virtual void QueueNextState(iState* state) override;
		virtual void SetID(int ID) override;
		virtual int GetID() override;
		virtual iState* GetCurrentState() override;
		virtual bool IsTransitioning() override;

	protected:
		int _stateMachineID = 0;
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;
		bool _makeTransition = false;

		virtual void _DestroyCurrentState();
		virtual void _MakeTransition() override;
	};
}