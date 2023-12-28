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
			if (_vecHurtBoxData.empty())
			{
				return nullptr;
			}

			for (auto i = _vecHurtBoxData.begin(); i != _vecHurtBoxData.end(); i++)
			{
				if ((*i).GetFrame() == frame)
				{
					return &(*i);
				}
			}

			return nullptr;
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