#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteType.h"

#include "iPlayer.h"

namespace RB::Collisions
{
	class AttackRegister
	{
	public:
		RB::Players::iPlayer* attacker = nullptr;
		RB::Players::iPlayer* target = nullptr;

		RB::Sprites::SpriteType attackerSpriteType = RB::Sprites::SpriteType::NONE;

		olc::vf2d collisionPoint = { 0.0f, 0.0f };
		bool targetIsOnRightSide = true;
	};
}