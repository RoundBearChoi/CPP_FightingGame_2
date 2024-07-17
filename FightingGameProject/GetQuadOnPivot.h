#pragma once

#include <array>

#include "Vector2.h"
#include "PivotType.h"

namespace RB::Sprites
{
	extern std::array<RB::Vector2, 4> GetQuadOnPivot(PivotType pivotType, float width, float height, RB::Vector2 pos);
}
