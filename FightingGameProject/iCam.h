#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Cam
{
	class iCam
	{
	public:
		virtual ~iCam() = default;

	public:
		virtual olc::vi2d GetPosition() = 0;
		virtual olc::vf2d GetRelativePosition(olc::vf2d pos) = 0;
	};
}