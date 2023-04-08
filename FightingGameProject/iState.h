#pragma once

/// <summary>
/// forward declare iStateMachine
/// </summary>
class iStateMachine;

namespace RB::StateMachine
{
	class iState
	{
	public:
		virtual ~iState() {}

		virtual void SetStateMachine(iStateMachine* stateMachine) = 0;
		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void QueueNextState(iState* nextState) = 0;
	};
}