#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "CurrentCam.h"

namespace RB::Render
{
	class LineRenderer
	{
	public:
		LineRenderer();
		~LineRenderer();

	public:
		void Init();
		void RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint);
	};
}