#pragma once
#include "iState.h"

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
		virtual void SetID(size_t ID) = 0;
		virtual size_t GetID() = 0;
		virtual iState* GetCurrentState() = 0;
		virtual bool IsTransitioning() = 0;
		
	protected:
		virtual void _MakeTransition() = 0;
	};
}