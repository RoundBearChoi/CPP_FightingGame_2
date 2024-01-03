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
		void RenderLine(const olc::vf2d& p1, const olc::vf2d& p2, olc::Pixel tint);
	};
}