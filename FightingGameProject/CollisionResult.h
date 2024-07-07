#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteType.h"
#include "CollisionType.h"

#include "iPlayer.h"

namespace RB::Collisions
{
	class CollisionResult
	{
	public:
		RB::Players::iPlayer* mAttacker = nullptr;
		RB::Players::iPlayer* mTarget = nullptr;
		olc::vf2d mCollisionPoint = { 0, 0 };
		CollisionType mCollisionType = CollisionType::NONE;
		RB::Sprites::SpriteType mAttackerSpriteType = RB::Sprites::SpriteType::NONE;
	};
}