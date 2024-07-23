#pragma once

#include "CharacterType.h"

namespace RB::Players
{
	class MoveSpecs
	{
	public:
		RB::Players::CharacterType mCharacterType = RB::Players::CharacterType::NONE;

		float				mWalk_Forward_Speed = 0;
		float				mWalk_Back_Speed = 0;
		unsigned int		mJumpUp_totalFrames = 0;
		float				mJumpUp_speedMultiplier = 0.0f;
		unsigned int		mJumpUp_Forward_totalFrames = 0;
		float				mJumpUp_Forward_speedMultiplier = 0.0f;
	};
}
