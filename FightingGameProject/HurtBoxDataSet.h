#pragma once
#include <vector>
#include "SpriteID.h"
#include "HurtBoxData.h"

namespace RB::HurtBox
{
	class HurtBoxDataSet
	{
	public:
		HurtBoxDataSet() = default;
		~HurtBoxDataSet() = default;

	public:
		RB::Sprites::SpriteID mSpriteID = RB::Sprites::SpriteID::NONE;
		HurtBoxData* mArrHurtBoxes = nullptr;
	};
}