#pragma once

#include "../Sprites/SpriteType.h"
#include "../Players/iPlayer.h"
#include "../Collisions/CollisionType.h"

namespace RB::Collisions
{
	class AttackRegister
	{
	public:
		Players::iPlayer* attacker = nullptr;
		Players::iPlayer* target = nullptr;

		Sprites::SPRITE_TYPE attackerSpriteType = Sprites::SPRITE_TYPE::NONE;

		Vector2 collisionPoint = { 0.0f, 0.0f };
		bool targetIsOnRightSide = true;
		bool targetIsCrouching = false;
		CollisionType collisionType = CollisionType::NONE;
	};
}
