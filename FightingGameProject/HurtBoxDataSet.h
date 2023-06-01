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

		HurtBoxData* GetHurtBoxDataByFrame(size_t frame)
		{
			HurtBoxData* result = _FindHurtBoxDataByFrame(frame);

			if (result != nullptr)
			{
				return result;
			}

			HurtBoxData data;
			data.SetFrameNameAndParse("frame_" + std::to_string(frame));
			data.AddAABB(RB::Collisions::AABB{ -25.0f, 25.0f, 50.0f, 50.0f });

			_vecHurtBoxData.push_back(data);

			return _FindHurtBoxDataByFrame(frame);
		}

		RB::Sprites::SpriteEnum GetSpriteEnum()
		{
			return _spriteEnum;
		}

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<HurtBoxData> _vecHurtBoxData;

	private:
		HurtBoxData* _FindHurtBoxDataByFrame(size_t frame)
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
	};
}