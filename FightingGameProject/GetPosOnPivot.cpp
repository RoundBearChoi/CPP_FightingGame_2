#include "GetPosOnPivot.h"

std::array<olc::vf2d, 4> RB::Sprites::GetPosOnPivot(PivotType pivotType, float width, float height, olc::vf2d pos)
{
	float halfWidth = width * 0.5f;
	float halfHeight = height * 0.5f;

	std::array<olc::vf2d, 4> points;

	if (pivotType == RB::Sprites::PivotType::CENTER)
	{
		points = {
			olc::vf2d{ pos.x - halfWidth, pos.y - halfHeight },
			olc::vf2d{ pos.x - halfWidth, pos.y + halfHeight },
			olc::vf2d{ pos.x + halfWidth, pos.y + halfHeight },
			olc::vf2d{ pos.x + halfWidth, pos.y - halfHeight },
		};
	}
	else if (pivotType == RB::Sprites::PivotType::BOTTOM_CENTER)
	{
		points = {
			olc::vf2d{ pos.x - halfWidth, pos.y - height },
			olc::vf2d{ pos.x - halfWidth, pos.y },
			olc::vf2d{ pos.x + halfWidth, pos.y },
			olc::vf2d{ pos.x + halfWidth, pos.y - height },
		};
	}
	else if (pivotType == RB::Sprites::PivotType::BOTTOM_LEFT)
	{
		points = {
			olc::vf2d{ pos.x, pos.y - height },
			olc::vf2d{ pos.x, pos.y },
			olc::vf2d{ pos.x + width, pos.y },
			olc::vf2d{ pos.x + width, pos.y - height },
		};
	}
	else if (pivotType == RB::Sprites::PivotType::BOTTOM_RIGHT)
	{
		points = {
			olc::vf2d{ pos.x - width, pos.y - height },
			olc::vf2d{ pos.x - width, pos.y },
			olc::vf2d{ pos.x, pos.y },
			olc::vf2d{ pos.x, pos.y - height },
		};
	}

	return points;
}
