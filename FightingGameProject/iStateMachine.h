#pragma once
#include "iState.h"

namespace RB::States
{
	class iStateMachine
	{
	public:
		virtual ~iStateMachine() {}

		virtual void Init(iState *state) = 0;
		virtual void QueueNextState(iState* state) = 0;
	};
}