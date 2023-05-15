#pragma once
#include <iostream>
#include <vector>
#include "iStateMachine.h"

namespace RB::States
{
	class ActiveStateMachines
	{
	public:
		ActiveStateMachines() = delete;
		~ActiveStateMachines() = delete;

	public:
		static void Init();
		static void OnEnd();

	public:
		static void AddStateMachine(iStateMachine* stateMachine);
		static void ResetID();
		static int GetID();

	private:
		static inline int _cumulatedID = 0;
		static inline std::vector<iStateMachine*> _vecStateMachines;
	};
}