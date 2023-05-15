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
		~ManualTransitioner();

	public:
		void OnEnter(size_t stateMachineID, RB::States::iState* prev, RB::States::iState* next);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		bool _ToPrev();
		bool _ToNext();

	private:
		size_t _stateMachineID = 0;
		RB::States::iState* _prevState = nullptr;
		RB::States::iState* _nextState = nullptr;
		bool _transitioning = false;
	};
}