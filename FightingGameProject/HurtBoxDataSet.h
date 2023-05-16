#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HurtBoxData.h"

namespace RB::HurtBox
{
	class HurtBoxDataSet
	{
	public:
		HurtBoxDataSet() = default;
		~HurtBoxDataSet() = default;

	public:
		RB::Sprites::SpriteEnum mSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<HurtBoxData> mData;
	};
}