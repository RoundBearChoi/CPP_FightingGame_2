#include "ControllerBase.h"

namespace RB::Controllers
{
	void ControllerBase::SetHash(std::string str)
	{
		//_hash = std::hash<std::string>{}(str);

		std::hash<std::string> hasher;

		_hash = hasher(str);
	}

	size_t ControllerBase::GetHash()
	{
		return _hash;
	}
}