#include "HBox_Layer_1.h"

namespace RB::HBox
{
	HBox_Layer_1::HBox_Layer_1(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;
	}

	void HBox_Layer_1::OnFixedUpdate()
	{
		for (auto i = _vecHB_L0.begin(); i != _vecHB_L0.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	void HBox_Layer_1::AddHBoxData(HBox_Layer_0 data)
	{
		_vecHB_L0.push_back(data);
	}

	const std::vector<HBox_Layer_0>& HBox_Layer_1::GetVecL0()
	{
		return _vecHB_L0;
	}

	HBox_Layer_0* HBox_Layer_1::GetHBoxDataByFrame(unsigned int frame)
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

	RB::Sprites::SpriteEnum HBox_Layer_1::GetSpriteEnum()
	{
		return _spriteEnum;
	}
}