#pragma once

#include <array>

#include "PivotType.h"

#include "../Vector2.h"

namespace RB::Sprites
{
	extern std::array<RB::Vector2, 4> GetQuadOnPivot(PivotType pivotType, float width, float height, RB::Vector2 pos);
}

// Global variable declaration
extern bool upIsNegativeY;