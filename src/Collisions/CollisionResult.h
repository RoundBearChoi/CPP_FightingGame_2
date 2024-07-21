#pragma once

#include "CollisionType.h"

#include "../SpriteType.h"

#include "../iPlayer.h"

namespace RB::Collisions
{
	class CollisionResult
	{
	public:
		RB::Players::iPlayer* mAttacker = nullptr;
		RB::Players::iPlayer* mTarget = nullptr;
		RB::Vector2 mCollisionPoint = { 0, 0 };
		RB::Sprites::SpriteType mAttackerSpriteType = RB::Sprites::SpriteType::NONE;
		CollisionType mCollisionType = CollisionType::NONE;
	};
}
