#pragma once
#include "olcPixelGameEngine.h"

using namespace olc;

namespace RB::Players
{
	class iPlayer
	{
	public:
		virtual ~iPlayer() {};

		virtual vf2d GetPosition() = 0;
		virtual void Move(vf2d moveAmount) = 0;
	};
}