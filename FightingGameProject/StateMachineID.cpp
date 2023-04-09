#include "StateMachineID.h"

namespace RB::States
{
	int StateMachineID::GetID()
	{
		_cumulatedID++;

		return _cumulatedID;
	}
}