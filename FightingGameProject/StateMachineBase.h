#pragma once
#include <iostream>
#include "iStateMachine.h"

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
		virtual void SetID(size_t ID) override;
		virtual size_t GetID() override;
		virtual iState* GetCurrentState() override;
		virtual bool IsTransitioning() override;

	protected:
		size_t _stateMachineID = 0;
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;

		virtual void _DestroyCurrentState();
		virtual void _MakeTransition() override;
	};
}