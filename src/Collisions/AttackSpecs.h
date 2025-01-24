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

			Sprites::SpriteType mSpriteType = Sprites::SpriteType::NONE;
			Collisions::AttackStrengthType mAttackStrengthType = Collisions::AttackStrengthType::NONE;
			int mDamage = 0;
			int mHitStop = 0;
			int mMinimumFixedUpdatesSinceHit = 0;
			int mMaxHits = 0;
	};
}