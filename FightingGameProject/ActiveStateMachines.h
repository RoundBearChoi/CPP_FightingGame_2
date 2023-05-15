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
		static iStateMachine* GetStateMachine(size_t id);
		static void ResetID();
		static size_t GetID();

	private:
		static inline size_t _cumulatedID = 0;
		static inline std::vector<iStateMachine*> _vecStateMachines;
	};
}