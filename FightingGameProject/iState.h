#pragma once

namespace RB::StateMachine
{
	class iState
	{
	public:
		virtual void OnEnter() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void QueueNextState(iState* nextState);
	};
}