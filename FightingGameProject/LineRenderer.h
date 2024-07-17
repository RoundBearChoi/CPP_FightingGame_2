#pragma once

#include "Vector2.h"
#include "olcPixelGameEngine.h"

namespace RB::Render
{
	class LineRenderer
	{
	public:
		LineRenderer() = default;
		~LineRenderer() = default;

	public:
		void RenderLine(const RB::Vector2& p1, const RB::Vector2& p2, olc::Pixel tint);
	};
}
