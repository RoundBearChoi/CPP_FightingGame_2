#pragma once
#include "iState.h"

namespace RB::StateMachine
{
	class iStateMachine
	{
	public:
		virtual ~iStateMachine() {}

		virtual void QueueNextState(iState* state) = 0;
	};
}