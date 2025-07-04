#pragma once

#include <array>
#include <cmath>

#include "PivotType.h"

#include "../Vector2.h"
#include "../RB_PI.h"

namespace RB::Sprites
{
	extern std::array<RB::Vector2, 4>FlipQuad(Sprites::PivotType pivotType, std::array<RB::Vector2, 4> arr);
	extern RB::Vector2 GetCenter(std::array<RB::Vector2, 4> arr);
	extern RB::Vector2 RotatePoint(RB::Vector2 center, RB::Vector2 point, float angle);
	extern std::array<RB::Vector2, 4> RotateQuad(std::array<RB::Vector2, 4> arr, float angle);
}
