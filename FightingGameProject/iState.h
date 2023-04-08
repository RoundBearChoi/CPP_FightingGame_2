#pragma once

/// <summary>
/// forward declare iStateMachine
/// </summary>
//class RB::StateMachine::iStateMachine;

namespace RB::States
{
	class iState
	{
	public:
		virtual ~iState() {}

		//virtual void SetStateMachine(RB::StateMachine::iStateMachine* stateMachine) = 0;
		virtual void QueueNextState(iState* nextState) = 0;

		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}