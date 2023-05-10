#pragma once
#include "iState.h"

namespace RB::States
{
	class iStateMachine
	{
	public:
		virtual ~iStateMachine() = default;

		virtual void Init(iState *state) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void QueueNextState(iState* state) = 0;
		virtual void SetID(int ID) = 0;
		virtual int GetID() = 0;
		virtual iState* GetCurrentState() = 0;
		virtual bool IsTransitioning() = 0;
		
	protected:
		virtual void _MakeTransition() = 0;
	};
}