#pragma once
#include "iPlayer.h"

namespace RB::States
{
	class iStateMachine; // forward declare

	class iState
	{
	public:
		virtual ~iState() {}

	public:
		virtual void SetStateMachine(iStateMachine* stateMachine) = 0;
		virtual void QueueNextState(iState* nextState) = 0;
		virtual void AddCumulatedFixedUpdate() = 0;
		virtual unsigned int GetCumulatedFixedUpdates() = 0;
		virtual RB::Players::iPlayer* GetOwnerPlayer() = 0;

	public:
		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}