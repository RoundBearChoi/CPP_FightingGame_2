#include "ControllerBase.h"

namespace RB::Controllers
{
	void ControllerBase::SetHash(std::string str)
	{
		_hash = std::hash<std::string>{}(str);
	}

	size_t ControllerBase::GetHash()
	{
		return _hash;
	}
}