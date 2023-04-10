#pragma once
#include "iController.h"
#include "olcPixelGameEngine.h"
namespace RB::Cam
{
	class iGameCamController : public RB::Controllers::iController
	{
	public:
		virtual olc::vi2d GetCamPos() = 0;
		virtual olc::vi2d GetRelativePos(olc::vi2d pos) = 0;
	};
}