#include "HBoxData.h"

namespace RB::HBox
{
	HBoxData::HBoxData(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
	{
		_frameName = frameName;
		//_vecAABB = vecAABB;
		_frame = _ParseFrame(frameName);

		for (auto i = vecAABB.begin(); i != vecAABB.end(); i++)
		{
			_selector.PushBack(*i);
		}
	}

	HBoxData::~HBoxData()
	{

	}

	void HBoxData::Init()
	{

	}

	void HBoxData::OnFixedUpdate()
	{
		_selector.OnFixedUpdate();
	}

	unsigned int HBoxData::GetFrame()
	{
		return _frame;
	}

	const std::vector<RB::Collisions::AABB>& HBoxData::GetVecAABBs()
	{
		const std::vector<RB::Collisions::AABB>& vec = _selector.GetVector();

		return vec;
		
		//return _vecAABB;
	}

	RB::Collisions::AABB* HBoxData::GetSelectedAABB()
	{
		RB::Collisions::AABB* aabb = _selector.GetSelected();

		return aabb;

		//if (!_selectionInitialized)
		//{
		//	_selected = _vecAABB.begin();
		//	_selectionInitialized = true;
		//}
		//
		//return &*_selected;
	}

	void HBoxData::UpSelection()
	{
		_selector.SelectUp();

		//if (_selected == _vecAABB.end() - 1)
		//{
		//	_selected = _vecAABB.begin();
		//}
		//else
		//{
		//	_selected++;
		//}
	}

	void HBoxData::DownSelection()
	{
		_selector.SelectDown();

		//if (_selected == _vecAABB.begin())
		//{
		//	_selected = _vecAABB.end() - 1;
		//}
		//else
		//{
		//	_selected--;
		//}
	}

	RB::Collisions::AABB& HBoxData::GetAABB(unsigned int index)
	{
		RB::Collisions::AABB* aabb = _selector.GetByIndex(index);

		return *aabb;

		//return _vecAABB[index];
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
		_selector.PushBack(aabb);

		//_vecAABB.push_back(aabb);
		//
		//if (_selectionInitialized)
		//{
		//	_selected = _vecAABB.end();
		//}
	}

	//bool HBoxData::DeleteAABB(unsigned int index)
	//{
	//	if (index >= _vecAABB.size())
	//	{
	//		return false;
	//	}
	//
	//	if (_vecAABB.size() == 1)
	//	{
	//		RB::Collisions::AABB aabb{ 0, 0, 0, 0 };
	//
	//		_vecAABB[0].ForceAABB(aabb);
	//
	//		return false;
	//	}
	//
	//	_vecAABB.erase(_vecAABB.begin() + index);
	//
	//	return true;
	//}

	void HBoxData::DeleteSelectedAABB()
	{
		_selector.EraseSelected();

		//if (_vecAABB.size() == 1)
		//{
		//	RB::Collisions::AABB aabb{ 0, 0, 0, 0 };
		//
		//	_vecAABB[0].ForceAABB(aabb);
		//
		//	_selected = _vecAABB.begin();
		//}
		//else
		//{
		//	_selected = _vecAABB.erase(_selected);
		//}
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