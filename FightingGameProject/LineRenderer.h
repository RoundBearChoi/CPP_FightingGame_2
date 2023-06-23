#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "ControllerGetter.h"
#include "CamController.h"

namespace RB::Render
{
	class LineRenderer
	{
	public:
		LineRenderer() = default;
		~LineRenderer() = default;

	public:
		void Init();
		void RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint);

	//private:
	//	RB::Controllers::ControllerGetter<RB::Cam::CamController> _getter_camController;
	};
}