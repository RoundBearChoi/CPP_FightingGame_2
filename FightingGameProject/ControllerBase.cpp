#include "ControllerBase.h"

namespace RB::Controllers
{
	string ControllerBase::GetName()
	{
		return _name;
	}

	void ControllerBase::_SetName(string name)
	{
		_name = name;
	}
}