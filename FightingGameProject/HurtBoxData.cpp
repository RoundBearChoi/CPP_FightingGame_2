#include "HurtBoxData.h"

namespace RB::HurtBox
{
	HurtBoxData::HurtBoxData(size_t index, std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
	{
		_index = index;
		_frameName = frameName;
		_vecAABB = vecAABB;

		_frame = _ParseFrame(frameName);
	}

	size_t HurtBoxData::GetIndex()
	{
		return _index;
	}

	size_t HurtBoxData::GetFrame()
	{
		return _frame;
	}

	size_t HurtBoxData::GetDataCount()
	{
		return _vecAABB.size();
	}

	RB::Collisions::AABB& HurtBoxData::GetAABB(size_t index)
	{
		return _vecAABB[index];
	}
}