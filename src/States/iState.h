#pragma once

namespace RB::States
{
	class iState
	{
	public:
		iState() = default;
		virtual ~iState() = default;

	public:
		virtual unsigned int GetStateID() = 0;
		virtual void SetStateMachineID(unsigned int id) = 0;
		virtual unsigned int GetStateMachineID() = 0;
		virtual void SetStateMachineIDs_Recursively() = 0;
		virtual void SetIsTransitioning(bool status) = 0;
		virtual bool IsTransitioning() = 0;
		virtual void AddCumulatedFixedUpdate() = 0;
		virtual unsigned int GetCumulatedFixedUpdates() = 0;
		virtual bool ContainsState_Recursive(unsigned int stateID) = 0;
		virtual void LogStateEnter() = 0;

	public:
		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void ErasePreviousStates() = 0;
	};
}
