#pragma once

#include <array>

#include "olcPixelGameEngine.h"

#include "PivotType.h"

namespace RB::Sprites
{
	extern std::array<olc::vf2d, 4> GetQuadOnPivot(PivotType pivotType, float width, float height, olc::vf2d pos);
}
