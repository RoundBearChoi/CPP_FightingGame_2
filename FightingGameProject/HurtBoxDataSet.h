#pragma once
#include <vector>
#include "SpriteID.h"
#include "HurtBoxSpecs.h"

namespace RB::HurtBox
{
	class HurtBoxDataSet
	{
	public:
		HurtBoxDataSet() = default;
		~HurtBoxDataSet() = default;

	public:
		RB::Sprites::SpriteID mSpriteID = RB::Sprites::SpriteID::NONE;
		std::vector<HurtBoxSpecs> mVecSpecs;
		size_t mFrame = 0;
	};
}