#include "FlipQuad.h"

namespace RB::Sprites
{
	std::array<RB::Vector2, 4> FlipQuad(Sprites::PivotType pivotType, std::array<RB::Vector2, 4> arr)
	{
		std::array<RB::Vector2, 4> flipped;

		if (pivotType == Sprites::PivotType::BOTTOM_CENTER || pivotType == Sprites::PivotType::CENTER)
		{
			flipped[0] = arr[3];
			flipped[1] = arr[2];
			flipped[2] = arr[1];
			flipped[3] = arr[0];
		}

		return flipped;
	}

	RB::Vector2 GetCenter(std::array<RB::Vector2, 4> arr)
	{
		RB::Vector2 center;

		center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x) / 4.0f;
		center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y) / 4.0f;

		return center;
	}

	RB::Vector2 RotatePoint(RB::Vector2 center, RB::Vector2 point, float angle)
	{
		float radians = angle * (RB_PI / 180.0f);

		float s = sinf(radians);
		float c = cosf(radians);

		// translate point back to origin:
		RB::Vector2 vec = point - center;

		// rotate point
		float x = vec.x * c - vec.y * s;
		float y = vec.x * s + vec.y * c;

		// translate point back:
		RB::Vector2 result;
		result.x = x + center.x;
		result.y = y + center.y;

		return result;
	}

	std::array<RB::Vector2, 4> RotateQuad(std::array<RB::Vector2, 4>arr, float angle)
	{
		// temp - assuming center pivot for now
		
		RB::Vector2 center = GetCenter(arr);

		std::array<RB::Vector2, 4> quad;

		quad[0] = RotatePoint(center, arr[0], angle);
		quad[1] = RotatePoint(center, arr[1], angle);
		quad[2] = RotatePoint(center, arr[2], angle);
		quad[3] = RotatePoint(center, arr[3], angle);

		return quad;
	}
}
