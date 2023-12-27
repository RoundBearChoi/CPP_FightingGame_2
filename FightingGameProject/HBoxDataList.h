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

		const std::vector<HBoxData>& GetVecHBoxData()
		{
			return _vecHurtBoxData;
		}

		//unsigned int GetSize()
		//{
		//	return _vecHurtBoxData.size();
		//}

		/// <summary>
		/// 0, 0 by default if no data found
		/// </summary>
		/// <param name="frame"></param>
		/// <returns></returns>
		HBoxData* GetHBoxDataByFrame(unsigned int frame)
		{
			HBoxData* result = _FindHBoxDataByFrame(frame);

			if (result != nullptr)
			{
				return result;
			}

			HBoxData data;
			data.SetFrameNameAndParse("frame_" + std::to_string(frame));
			data.AddAABB(RB::Collisions::AABB{ 0.0f, 0.0f, 0.0f, 0.0f }); //width height size all 0
			
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
		HBoxData* _FindHBoxDataByFrame(unsigned int frame)
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
	};
}