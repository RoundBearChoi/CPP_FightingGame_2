#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerID.h"

namespace RB::Players
{
	class iPlayer
	{
	public:
		virtual ~iPlayer() {};

	public:
		virtual olc::vi2d GetPlayerBox() = 0;
		virtual PlayerID GetPlayerID() = 0;
		virtual int GetStateMachineID() = 0;
		virtual void Move(olc::vi2d moveAmount) = 0;
		virtual olc::vi2d GetPosition() = 0;
		virtual void SetPosition(olc::vi2d pos) = 0;
	};
}