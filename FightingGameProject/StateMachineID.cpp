#include <iostream>
#include "StateMachineID.h"

namespace RB::States
{
	int StateMachineID::GetID()
	{
		_cumulatedID++;

		std::cout << "creating statemachine id: " << _cumulatedID;

		return _cumulatedID;
	}
}