#pragma once
#include "iPlayer.h"
#include "SpriteID.h"

namespace RB::States
{
	class iStateMachine; // forward declare

	class iState
	{
	public:
		iState() = default;
		virtual ~iState() = default;

	public:
		virtual void SetStateMachine(iStateMachine* stateMachine) = 0;
		virtual iStateMachine* GetStateMachine() = 0;
		virtual void QueueNextState(iState* nextState) = 0;
		virtual void AddCumulatedFixedUpdate() = 0;
		virtual size_t GetCumulatedFixedUpdates() = 0;
		virtual RB::Sprites::SpriteID GetSpriteID() = 0;

	public:
		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}