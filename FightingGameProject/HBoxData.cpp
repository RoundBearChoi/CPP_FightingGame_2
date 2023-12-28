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

	const std::vector<RB::Collisions::AABB>& HBoxData::GetVecAABBs()
	{
		return _vecAABB;
	}

	RB::Collisions::AABB* HBoxData::GetSelectedAABB()
	{
		if (!_selectionInitialized)
		{
			_selected = _vecAABB.begin();
			_selectionInitialized = true;
		}

		return &*_selected;
	}

	void HBoxData::UpSelection()
	{
		if (_selected == _vecAABB.end() - 1)
		{
			_selected = _vecAABB.begin();
		}
		else
		{
			_selected++;
		}
	}

	void HBoxData::DownSelection()
	{
		if (_selected == _vecAABB.begin())
		{
			_selected = _vecAABB.end() - 1;
		}
		else
		{
			_selected--;
		}
	}

	RB::Collisions::AABB& HBoxData::GetAABB(unsigned int index)
	{
		return _vecAABB[index];
	}

	const std::string& HBoxData::GetFrameName()
	{
		return _frameName;
	}

	void HBoxData::SetFrameNameAndParse(const std::string& name)
	{
		_frameName = name;
		_frame = _ParseFrame(name);
	}

	void HBoxData::AddAABB(RB::Collisions::AABB aabb)
	{
		_vecAABB.push_back(aabb);

		if (_selectionInitialized)
		{
			_selected = _vecAABB.end();
		}
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

	void HBoxData::DeleteSelectedAABB()
	{
		if (_vecAABB.size() == 1)
		{
			RB::Collisions::AABB aabb{ 0, 0, 0, 0 };

			_vecAABB[0].ForceAABB(aabb);

			_selected = _vecAABB.begin();
		}
		else
		{
			_selected = _vecAABB.erase(_selected);
		}
	}

	RB::Selector<RB::Collisions::AABB>* HBoxData::GetSelector()
	{
		return &_selector;
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