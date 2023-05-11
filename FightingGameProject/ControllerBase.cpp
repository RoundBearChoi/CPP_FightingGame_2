#include "ControllerBase.h"

namespace RB::Controllers
{
	void ControllerBase::SetHash(const type_info& ti)
	{
		std::string name = ti.name();

		std::hash<std::string> hasher;

		_hash = hasher(name);
	}

	size_t ControllerBase::GetHash()
	{
		return _hash;
	}
}