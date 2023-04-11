#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Cam
{
	class iCam
	{
	public:
		virtual ~iCam() {}

	public:
		virtual olc::vi2d GetPosition() = 0;
	};
}