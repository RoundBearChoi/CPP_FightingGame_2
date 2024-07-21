#pragma once

#include "../SpriteType.h"

#include "../iPlayer.h"

namespace RB::Collisions
{
	class AttackRegister
	{
	public:
		RB::Players::iPlayer* attacker = nullptr;
		RB::Players::iPlayer* target = nullptr;

		RB::Sprites::SpriteType attackerSpriteType = RB::Sprites::SpriteType::NONE;

		RB::Vector2 collisionPoint = { 0.0f, 0.0f };
		bool targetIsOnRightSide = true;
	};
}
