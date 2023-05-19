#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HurtBoxData.h"

namespace RB::HurtBox
{
	class HurtBoxDataSet
	{
	public:
		HurtBoxDataSet(RB::Sprites::SpriteEnum spriteEnum)
		{
			_spriteEnum = spriteEnum;
		}

		~HurtBoxDataSet() = default;

	public:
		void AddHurtBoxData(HurtBoxData data)
		{
			_vecHurtBoxData.push_back(data);
		}

		HurtBoxData* GetHurtBoxDataByIndex(size_t index)
		{
			if (index >= _vecHurtBoxData.size())
			{
				return nullptr;
			}

			return &_vecHurtBoxData[index];
		}

		HurtBoxData* GetHurtBoxDataByFrame(size_t frame)
		{
			for (size_t i = 0; i < _vecHurtBoxData.size(); i++)
			{
				if (_vecHurtBoxData[i].GetFrame() == frame)
				{
					return &_vecHurtBoxData[i];
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
		std::vector<HurtBoxData> _vecHurtBoxData;
	};
}