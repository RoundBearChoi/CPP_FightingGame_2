#pragma once
#include "SpriteEnum.h"

namespace RB::States
{
	class iState
	{
	public:
		iState() = default;
		virtual ~iState() = default;

	public:
		virtual void SetStateMachineID(size_t id) = 0;
		virtual size_t GetStateMachineID() = 0;
		virtual void SetTransitionStatus(bool status) = 0;
		virtual bool IsTransitioning() = 0;
		virtual void AddCumulatedFixedUpdate() = 0;
		virtual size_t GetCumulatedFixedUpdates() = 0;
		virtual bool Entered() = 0;
		virtual void Entered(bool entered) = 0;

	public:
		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}