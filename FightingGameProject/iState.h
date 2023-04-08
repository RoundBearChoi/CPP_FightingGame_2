#pragma once

namespace RB::States
{
	class iStateMachine; // forward declare

	class iState
	{
	public:
		virtual ~iState() {}

		virtual void SetStateMachine(iStateMachine* stateMachine) {}
		virtual void QueueNextState(iState* nextState) = 0;

		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}