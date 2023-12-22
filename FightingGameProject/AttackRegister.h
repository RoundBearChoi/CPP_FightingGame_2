#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"

namespace RB::Collisions
{
	class AttackRegister
	{
	public:
		RB::Players::iPlayer* attacker = nullptr;
		RB::Players::iPlayer* target = nullptr;

		olc::vf2d collisionPos = { 0.0f, 0.0f };
		bool targetIsOnRightSide = true;
	};
}