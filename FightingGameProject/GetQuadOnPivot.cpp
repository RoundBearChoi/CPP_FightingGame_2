#include "GetQuadOnPivot.h"

std::array<RB::Vector2, 4> RB::Sprites::GetQuadOnPivot(PivotType pivotType, float width, float height, RB::Vector2 pos)
{
	float halfWidth = width * 0.5f;
	float halfHeight = height * 0.5f;

	std::array<RB::Vector2, 4> points;

	if (pivotType == RB::Sprites::PivotType::CENTER)
	{
		points = {
			RB::Vector2{ pos.x - halfWidth, pos.y - halfHeight },
			RB::Vector2{ pos.x - halfWidth, pos.y + halfHeight },
			RB::Vector2{ pos.x + halfWidth, pos.y + halfHeight },
			RB::Vector2{ pos.x + halfWidth, pos.y - halfHeight },
		};
	}
	else if (pivotType == RB::Sprites::PivotType::BOTTOM_CENTER)
	{
		points = {
			RB::Vector2{ pos.x - halfWidth, pos.y - height },
			RB::Vector2{ pos.x - halfWidth, pos.y },
			RB::Vector2{ pos.x + halfWidth, pos.y },
			RB::Vector2{ pos.x + halfWidth, pos.y - height },
		};
	}
	else if (pivotType == RB::Sprites::PivotType::BOTTOM_LEFT)
	{
		points = {
			RB::Vector2{ pos.x, pos.y - height },
			RB::Vector2{ pos.x, pos.y },
			RB::Vector2{ pos.x + width, pos.y },
			RB::Vector2{ pos.x + width, pos.y - height },
		};
	}
	else if (pivotType == RB::Sprites::PivotType::BOTTOM_RIGHT)
	{
		points = {
			RB::Vector2{ pos.x - width, pos.y - height },
			RB::Vector2{ pos.x - width, pos.y },
			RB::Vector2{ pos.x, pos.y },
			RB::Vector2{ pos.x, pos.y - height },
		};
	}

	return points;
}
