#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HBox_Layer_0.h"

namespace RB::HBox
{
	class HBoxDataList
	{
	public:
		HBoxDataList(RB::Sprites::SpriteEnum spriteEnum)
		{
			_spriteEnum = spriteEnum;
		}

		~HBoxDataList() = default;

	public:
		void OnFixedUpdate()
		{
			for (auto i = _vecHB_L0.begin(); i != _vecHB_L0.end(); i++)
			{
				(*i).OnFixedUpdate();
			}
		}

		void AddHBoxData(HBox_Layer_0 data)
		{
			_vecHB_L0.push_back(data);
		}

		const std::vector<HBox_Layer_0>& GetVecHBoxData()
		{
			return _vecHB_L0;
		}

		HBox_Layer_0* GetHBoxDataByFrame(unsigned int frame)
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

		RB::Sprites::SpriteEnum GetSpriteEnum()
		{
			return _spriteEnum;
		}

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<HBox_Layer_0> _vecHB_L0;
	};
}