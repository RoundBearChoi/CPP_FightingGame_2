#pragma once

#include <array>
#include <cmath>

#include "PivotType.h"

#include "../Vector2.h"

namespace RB::Sprites
{
	extern std::array<RB::Vector2, 4>FlipQuad(RB::Sprites::PivotType pivotType, std::array<RB::Vector2, 4> arr);
	extern Vector2 GetCenter(std::array<RB::Vector2, 4> arr);
	extern Vector2 RotatePoint(Vector2 center, Vector2 point, float angle);
	extern std::array<RB::Vector2, 4> RotateQuad(std::array<RB::Vector2, 4> arr, float angle);
}
