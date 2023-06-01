#include "HBoxData.h"

namespace RB::HBox
{
	HBoxData::HBoxData(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
	{
		_frameName = frameName;
		_vecAABB = vecAABB;

		_frame = _ParseFrame(frameName);
	}

	size_t HBoxData::GetFrame()
	{
		return _frame;
	}

	size_t HBoxData::GetAABBCount()
	{
		return _vecAABB.size();
	}

	RB::Collisions::AABB& HBoxData::GetAABB(size_t index)
	{
		return _vecAABB[index];
	}

	const std::string& HBoxData::GetFrameName()
	{
		return _frameName;
	}

	void HBoxData::ReserveAABBCapacity(size_t size)
	{
		_vecAABB.reserve(size);
	}

	void HBoxData::SetFrameNameAndParse(const std::string& name)
	{
		_frameName = name;
		_frame = _ParseFrame(name);
	}

	void HBoxData::AddAABB(RB::Collisions::AABB aabb)
	{
		_vecAABB.push_back(aabb);
	}

	bool HBoxData::DeleteAABB(size_t index)
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

	size_t HBoxData::_ParseFrame(const std::string& str)
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