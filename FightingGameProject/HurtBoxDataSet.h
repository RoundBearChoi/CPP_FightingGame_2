#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HurtBoxData.h"

namespace RB::HurtBox
{
	class HurtBoxDataSet
	{
	public:
		HurtBoxDataSet(RB::Sprites::SpriteEnum spriteEnum);
		~HurtBoxDataSet() = default;

	public:
		void AddHurtBoxData(HurtBoxData data);
		RB::Sprites::SpriteEnum GetSpriteEnum();

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<HurtBoxData> _vecHurtBoxData;
	};
}