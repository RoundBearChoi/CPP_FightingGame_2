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
		void AddHBoxData(HBoxData data)
		{
			_vecHurtBoxData.push_back(data);
		}

		size_t GetSize()
		{
			return _vecHurtBoxData.size();
		}

		/// <summary>
		/// adding default data if not found
		/// </summary>
		/// <param name="frame"></param>
		/// <returns></returns>
		HBoxData* GetHBoxDataByFrame(size_t frame)
		{
			HBoxData* result = _FindHBoxDataByFrame(frame);

			if (result != nullptr)
			{
				return result;
			}

			HBoxData data;
			data.SetFrameNameAndParse("frame_" + std::to_string(frame));
			data.AddAABB(RB::Collisions::AABB{ 0.0f, 0.0f, 0.0f, 0.0f }); //position & size 0 by default

			_vecHurtBoxData.push_back(data);

			return _FindHBoxDataByFrame(frame);
		}

		RB::Sprites::SpriteEnum GetSpriteEnum()
		{
			return _spriteEnum;
		}

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<HBoxData> _vecHurtBoxData;

	private:
		HBoxData* _FindHBoxDataByFrame(size_t frame)
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