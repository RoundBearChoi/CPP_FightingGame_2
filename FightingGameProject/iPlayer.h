#pragma once
#include "olcPixelGameEngine.h"

using namespace olc;

namespace RB::Players
{
	class iPlayer
	{
	public:
		virtual ~iPlayer() {};

	public:
		virtual vi2d GetPosition() = 0;
		virtual int GetPlayerIndex() = 0;
		virtual int GetStateMachineID() = 0;
		virtual void Move(vi2d moveAmount) = 0;
	};
}