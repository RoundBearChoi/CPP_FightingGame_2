#pragma once

#include "CollisionType.h"

#include "../Sprites/SpriteType.h"

#include "../Players/iPlayer.h"

namespace RB::Collisions
{
	class CollisionResult
	{
	public:
		Players::iPlayer* mAttacker = nullptr;
		Players::iPlayer* mTarget = nullptr;
		Vector2 mCollisionPoint = { 0, 0 };
		Sprites::SPRITE_TYPE mAttackerSpriteType = Sprites::SPRITE_TYPE::NONE;
		CollisionType mCollisionType = CollisionType::NONE;
	};
}
