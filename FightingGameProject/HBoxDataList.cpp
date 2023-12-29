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

	const std::vector<HBox_Layer_0>& HBoxDataList::GetVecL0()
	{
		return _vecHB_L0;
	}

	HBox_Layer_0* HBoxDataList::GetHBoxDataByFrame(unsigned int frame)
	{
		//failsafe
		if (_vecHB_L0.empty())
		{
			return nullptr;
		}

		//exising data
		for (auto i = _vecHB_L0.begin(); i != _vecHB_L0.end(); i++)
		{
			if ((*i).GetFrame() == frame)
			{
				return &(*i);
			}
		}

		//default data if no existing data
		HBox_Layer_0 L0;
		L0.SetFrameNameAndParse("frame_" + std::to_string(frame));

		_vecHB_L0.push_back(L0);

		//make sure to refresh iterators after making changes to the vector
		for (auto i = _vecHB_L0.begin(); i != _vecHB_L0.end(); i++)
		{
			(*i).GetSelector()->SetRefreshed(false);
		}

		return &(*(_vecHB_L0.end() - 1));
	}

	RB::Sprites::SpriteEnum HBoxDataList::GetSpriteEnum()
	{
		return _spriteEnum;
	}
}