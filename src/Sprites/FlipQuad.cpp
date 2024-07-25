#include "FlipQuad.h"

namespace RB::Sprites
{
	std::array<RB::Vector2, 4> FlipQuad(RB::Sprites::PivotType pivotType, std::array<RB::Vector2, 4> arr)
	{
		std::array<RB::Vector2, 4> flipped;

		if (pivotType == RB::Sprites::PivotType::BOTTOM_CENTER || pivotType == RB::Sprites::PivotType::CENTER)
		{
			flipped[0] = arr[3];
			flipped[1] = arr[2];
			flipped[2] = arr[1];
			flipped[3] = arr[0];
		}

		return flipped;
	}

	Vector2 GetCenter(std::array<RB::Vector2, 4> arr)
	{
		Vector2 center;

		center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x) / 4.0f;
		center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y) / 4.0f;

		return center;
	}

	Vector2 RotatePoint(Vector2 center, Vector2 point, float angle)
	{
		float s = sinf(angle);
		float c = cosf(angle);

		// translate point back to origin:
		point.x -= center.x;
		point.y -= center.y;

		// rotate point
		float xnew = point.x * c - point.y * s;
		float ynew = point.x * s + point.y * c;

		// translate point back:
		point.x = xnew + center.x;
		point.y = ynew + center.y;
		return point;
	}

	std::array<Vector2, 4> RotateQuad(std::array<Vector2, 4>arr, float angle)
	{
		// temp - assuming center pivot for now
		
		Vector2 center = GetCenter(arr);

		std::array<Vector2, 4> quad;

		quad[0] = RotatePoint(center, arr[0], angle);
		quad[1] = RotatePoint(center, arr[1], angle);
		quad[2] = RotatePoint(center, arr[2], angle);
		quad[3] = RotatePoint(center, arr[3], angle);

		return quad;
	}
}
