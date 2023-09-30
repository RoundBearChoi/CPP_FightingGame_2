#pragma once
#include "iPlayer.h"

namespace RB::Collisions
{
	class AttackRegister
	{
	public:
		RB::Players::iPlayer* target = nullptr;
		RB::Players::iPlayer* attacker = nullptr;

		bool targetWasFacingRight = true;
	};
}