#include "FlipQuad.h"

namespace RB::Sprites
{
	std::array<olc::vf2d, 4> FlipQuad(RB::Sprites::PivotType pivotType, std::array<olc::vf2d, 4> arr)
	{
		std::array<olc::vf2d, 4> flipped;

		if (pivotType == RB::Sprites::PivotType::BOTTOM_CENTER || pivotType == RB::Sprites::PivotType::CENTER)
		{
			flipped[0] = arr[3];
			flipped[1] = arr[2];
			flipped[2] = arr[1];
			flipped[3] = arr[0];
		}

		return flipped;
	}
}
