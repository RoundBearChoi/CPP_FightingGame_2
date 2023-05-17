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

		HurtBoxData& GetHurtBoxData(size_t index)
		{
			if (index >= _vecHurtBoxData.size())
			{
				return _vecHurtBoxData[_vecHurtBoxData.size() - 1];
			}

			return _vecHurtBoxData[index];
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