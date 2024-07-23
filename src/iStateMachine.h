#pragma once

#include "States/iState.h"

namespace RB::States
{
	class iStateMachine
	{
	public:
		iStateMachine() = default;
		virtual ~iStateMachine() = default;

		virtual void Init(iState *state) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual void QueueNextState(iState* state) = 0;
		virtual void OverrideNextState(RB::States::iState* state) = 0;
		virtual unsigned int GetID() = 0;
		virtual iState* GetCurrentState() = 0;
		virtual bool IsTransitioning() = 0;
		
	protected:
		virtual void _MakeTransition() = 0;
	};
}