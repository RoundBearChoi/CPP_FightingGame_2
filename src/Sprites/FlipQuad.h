#pragma once

#include <array>

#include "../Vector2.h"
#include "../PivotType.h"

namespace RB::Sprites
{
	extern std::array<RB::Vector2, 4>FlipQuad(RB::Sprites::PivotType pivotType, std::array<RB::Vector2, 4> arr);
}
