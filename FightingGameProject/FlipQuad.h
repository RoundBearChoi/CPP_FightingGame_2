#pragma once
#include <array>


#include "olcPixelGameEngine.h"

#include "PivotType.h"

namespace RB::Sprites
{
	extern std::array<olc::vf2d, 4>FlipQuad(RB::Sprites::PivotType pivotType, std::array<olc::vf2d, 4> arr);
}
