#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteType.h"

#include "iPlayer.h"

namespace RB::Collisions
{
	class CollisionResult
	{
	public:
		RB::Players::iPlayer* mOwner = nullptr;
		RB::Players::iPlayer* mTarget = nullptr;
		olc::vf2d mCollisionPoint = { 0, 0 };
		RB::Sprites::SpriteType mOwnerSpriteType = RB::Sprites::SpriteType::NONE;
	};
}