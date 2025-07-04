#pragma once

#include "AttackStrengthType.h"

#include "../Sprites/SpriteType.h"

namespace RB::Collisions
{
	class AttackSpecs
	{
		public:
			AttackSpecs() = default;
			~AttackSpecs() = default;

			Sprites::SPRITE_TYPE mSpriteType = Sprites::SPRITE_TYPE::NONE;
			Collisions::AttackStrengthType mAttackStrengthType = Collisions::AttackStrengthType::NONE;
			int mDamage = 0;
			int mHitStop = 0;
			int mMinimumFixedUpdatesSinceHit = 0;
			int mMaxHits = 0;
			int mDamageFrames = 0;
			int mBlockFrames = 0;
			int mMissFrames = 0;
	};
}
