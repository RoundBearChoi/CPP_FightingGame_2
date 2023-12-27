#include "HBoxData.h"

namespace RB::HBox
{
	HBoxData::HBoxData(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
	{
		_frameName = frameName;
		_vecAABB = vecAABB;

		_frame = _ParseFrame(frameName);
	}

	unsigned int HBoxData::GetFrame()
	{
		return _frame;
	}

	unsigned int HBoxData::GetAABBCount()
	{
		return _vecAABB.size();
	}

	const std::vector<RB::Collisions::AABB>& HBoxData::GetVecAABBs()
	{
		return _vecAABB;
	}

	RB::Collisions::AABB& HBoxData::GetAABB(unsigned int index)
	{
		return _vecAABB[index];
	}

	const std::string& HBoxData::GetFrameName()
	{
		return _frameName;
	}

	void HBoxData::ReserveAABBCapacity(unsigned int size)
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

	bool HBoxData::DeleteAABB(unsigned int index)
	{
		if (index >= _vecAABB.size())
		{
			return false;
		}

		if (_vecAABB.size() == 1)
		{
			RB::Collisions::AABB aabb{ 0, 0, 0, 0 };

			_vecAABB[0].ForceAABB(aabb);

			return false;
		}

		_vecAABB.erase(_vecAABB.begin() + index);

		return true;
	}

	unsigned int HBoxData::_ParseFrame(const std::string& str)
	{
		std::regex pattern("frame_");
		std::string replacement = "";
		std::string s = std::regex_replace(str, pattern, replacement);
		std::stringstream stream(s);
		unsigned int result;
		stream >> result;
		return result;
	}
}