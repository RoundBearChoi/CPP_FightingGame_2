#pragma once

#include <array>

#include "PivotType.h"

#include "../Vector2.h"

namespace RB::Sprites
{
	extern std::array<RB::Vector2, 4>FlipQuad(RB::Sprites::PivotType pivotType, std::array<RB::Vector2, 4> arr);
}
