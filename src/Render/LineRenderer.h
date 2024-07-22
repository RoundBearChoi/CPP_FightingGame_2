#pragma once

#include "../olcPixelGameEngine.h"

#include "../Vector2.h"

#include "../iCamController.h"

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
