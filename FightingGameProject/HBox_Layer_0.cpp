#include "HBox_Layer_0.h"

#include <regex>

namespace RB::HBox
{
	HBox_Layer_0::HBox_Layer_0(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
	{
		_frameName = frameName;
		_frame = _ParseFrame(frameName);

		for (auto i = vecAABB.begin(); i != vecAABB.end(); i++)
		{
			_selector.PushBack(*i);
		}
	}

	HBox_Layer_0::~HBox_Layer_0()
	{

	}

	void HBox_Layer_0::OnFixedUpdate()
	{
		_selector.OnFixedUpdate();
	}

	RB::iSelector<RB::Collisions::AABB>* HBox_Layer_0::GetSelector()
	{
		return &_selector;
	}

	unsigned int HBox_Layer_0::GetFrame()
	{
		return _frame;
	}

	const std::string& HBox_Layer_0::GetFrameName()
	{
		return _frameName;
	}

	void HBox_Layer_0::SetFrameNameAndParse(const std::string& name)
	{
		_frameName = name;
		_frame = _ParseFrame(name);
	}

	unsigned int HBox_Layer_0::_ParseFrame(const std::string& str)
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