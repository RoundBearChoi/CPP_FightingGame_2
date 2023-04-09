#include <iostream>
#include "StateMachineID.h"

namespace RB::States
{
	int StateMachineID::GetID()
	{
		_cumulatedID++;

		//std::cout << "creating statemachine id: " << _cumulatedID << std::endl;

		return _cumulatedID;
	}
}