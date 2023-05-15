#pragma once
#include "olcPixelGameEngine.h"
#include "ActiveStateMachines.h"
#include "iState.h"

namespace RB::States
{
	class ManualTransitioner
	{
	public:
		ManualTransitioner() = default;
		~ManualTransitioner() = default;

	public:
		void OnEnter(size_t stateMachineID, RB::States::iState* prev, RB::States::iState* next);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		size_t _stateMachineID = 0;
		RB::States::iState* _prevState = nullptr;
		RB::States::iState* _nextState = nullptr;
	};
}