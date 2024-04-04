#pragma once

#include "SpriteType.h"
#include "AttackStrengthType.h"

namespace RB::Collisions
{
	class AttackSpecs
	{
		public:
			AttackSpecs() = default;
			~AttackSpecs() = default;

			RB::Sprites::SpriteType mSpriteType = RB::Sprites::SpriteType::NONE;
			AttackStrengthType mAttackStrengthType = RB::AttackStrengthType::NONE;
			int mDamage = 0;
	};
}