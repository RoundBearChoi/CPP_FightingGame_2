#pragma once

namespace RB::States
{
	class StateMachineID
	{
	public:
		StateMachineID() = default;
		~StateMachineID() = default;

	public:
		static int GetID();

	private:
		static inline int _cumulatedID = 0;
	};
}