#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Players
{
	class iPlayer
	{
	public:
		virtual ~iPlayer() {};

	public:
		virtual olc::vi2d GetPosition() = 0;
		virtual int GetPlayerID() = 0;
		virtual int GetStateMachineID() = 0;
		virtual void Move(olc::vi2d moveAmount) = 0;
	};
}