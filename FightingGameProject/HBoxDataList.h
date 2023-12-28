#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HBoxData.h"

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
			for (auto i = _vecHurtBoxData.begin(); i != _vecHurtBoxData.end(); i++)
			{
				(*i).OnFixedUpdate();
			}
		}

		void AddHBoxData(HBoxData data)
		{
			_vecHurtBoxData.push_back(data);
		}

		const std::vector<HBoxData>& GetVecHBoxData()
		{
			return _vecHurtBoxData;
		}

		HBoxData* GetHBoxDataByFrame(unsigned int frame)
		{
			//failsafe
			if (_vecHurtBoxData.empty())
			{
				return nullptr;
			}

			//exising data
			for (auto i = _vecHurtBoxData.begin(); i != _vecHurtBoxData.end(); i++)
			{
				if ((*i).GetFrame() == frame)
				{
					return &(*i);
				}
			}

			//default data if no existing data
			HBoxData data;
			data.SetFrameNameAndParse("frame_" + std::to_string(frame));

			_vecHurtBoxData.push_back(data);

			for (auto i = _vecHurtBoxData.begin(); i != _vecHurtBoxData.end(); i++)
			{
				(*i).GetSelector()->SetRefreshed(false);
			}

			return &(*(_vecHurtBoxData.end() - 1));
		}

		RB::Sprites::SpriteEnum GetSpriteEnum()
		{
			return _spriteEnum;
		}

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<HBoxData> _vecHurtBoxData;
	};
}