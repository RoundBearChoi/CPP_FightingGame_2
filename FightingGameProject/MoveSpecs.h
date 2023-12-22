#pragma once

#include <cstdint> // for int32_t
#include <cmath>   // for float_t
#include <cstddef> // for size_t

#include "CharacterType.h"

namespace RB::Players::Specs
{
	class MoveSpecs
	{
	public:
		RB::Players::CharacterType mCharacterType = RB::Players::CharacterType::NONE;

		int32_t		mWalk_Forward_Speed = 0;
		int32_t		mWalk_Back_Speed = 0;
		size_t		mJumpUp_totalFrames = 0;
		float_t		mJumpUp_speedMultiplier = 0.0f;
		size_t		mJumpUp_Forward_totalFrames = 0;
		float_t		mJumpUp_Forward_speedMultiplier = 0.0f;
	};
}