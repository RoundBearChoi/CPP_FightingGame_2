#pragma once

namespace RB::States
{
	class StateMachineID
	{
	private:
		static inline int _cumulatedID = 0;

	public:
		static int GetID();
	};
}