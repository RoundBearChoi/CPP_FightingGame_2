#pragma once
#include <iostream>
#include "iLineRenderer.h"
#include "CurrentCam.h"

namespace RB::Render
{
	class LineRenderer : public iLineRenderer
	{
	public:
		LineRenderer();
		~LineRenderer() override;

	public:
		void Init() override;
		void RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint) override;
	};
}