#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HurtBoxSpecs.h"

namespace RB::HurtBox
{
	class HurtBoxData
	{
	public:
		HurtBoxData() = default;
		~HurtBoxData() = default;

	public:
		size_t mFrame = 0;
		std::vector<HurtBoxSpecs> mSpecs;
	};
}