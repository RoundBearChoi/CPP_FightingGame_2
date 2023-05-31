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

	size_t HurtBoxData::GetAABBCount()
	{
		return _vecAABB.size();
	}

	RB::Collisions::AABB& HurtBoxData::GetAABB(size_t index)
	{
		return _vecAABB[index];
	}

	void HurtBoxData::ReserveAABBCapacity(size_t size)
	{
		_vecAABB.reserve(size);
	}

	void HurtBoxData::SetIndex(size_t frame)
	{
		_index = frame;
	}

	void HurtBoxData::SetFrameName(const std::string& name)
	{
		_frameName = name;
		_frame = _ParseFrame(name);
	}

	void HurtBoxData::AddAABB(RB::Collisions::AABB aabb)
	{
		_vecAABB.push_back(aabb);
	}

	bool HurtBoxData::DeleteAABB(size_t index)
	{
		if (index >= _vecAABB.size())
		{
			return false;
		}

		if (_vecAABB.size() == 1)
		{
			return false;
		}

		_vecAABB.erase(_vecAABB.begin() + index);

		return true;
	}

	size_t HurtBoxData::_ParseFrame(const std::string& str)
	{
		std::regex pattern("frame_");
		std::string replacement = "";
		std::string s = std::regex_replace(str, pattern, replacement);
		std::stringstream stream(s);
		size_t result;
		stream >> result;
		return result;
	}
}