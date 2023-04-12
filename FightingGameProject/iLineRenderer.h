#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Render
{
	class iLineRenderer
	{
	public:
		virtual ~iLineRenderer() {}

	public:
		virtual void Init() = 0;
		virtual void RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint) = 0;
	};
}