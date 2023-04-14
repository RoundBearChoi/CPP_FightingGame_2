#pragma once
#include "iState.h"

namespace RB::States
{
	class StateComponentBase
	{
	public:
		~StateComponentBase() {}

	public:
		virtual void SetState(iState* state);

	public:
		virtual void OnEnter();
		virtual void OnExit();
		virtual void OnUpdate();
		virtual void OnFixedUpdate();

	protected:
		iState* _state = nullptr;
	};
}