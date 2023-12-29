#include "HBoxDataList.h"

namespace RB::HBox
{
	HBoxDataList::HBoxDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;
	}

	void HBoxDataList::OnFixedUpdate()
	{
		for (auto i = _vecHB_L0.begin(); i != _vecHB_L0.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	void HBoxDataList::AddHBoxData(HBox_Layer_0 data)
	{
		_vecHB_L0.push_back(data);
	}

	const std::vector<HBox_Layer_0>& HBoxDataList::GetVecHBoxData()
	{
		return _vecHB_L0;
	}
}