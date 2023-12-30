#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Render
{
	class LineRenderer
	{
	public:
		LineRenderer() = default;
		~LineRenderer() = default;

	public:
		void RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint);
	};
}