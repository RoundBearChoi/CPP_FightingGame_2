#pragma once

#include "CharacterType.h"

namespace RB::Players
{
	class MoveSpecs
	{
	public:
		Players::CharacterType mCharacterType = Players::CharacterType::NONE;

		float				mWalk_Forward_Speed = 0;
		float				mWalk_Back_Speed = 0;

		unsigned int		mJumpUp_totalFrames = 0;
		float				mJumpUp_speedMultiplier = 0.0f;
		
		unsigned int		mJumpForward_totalFrames = 0;
		float				mJumpForward_horSpeedMultiplier = 0.0f;
		float				mJumpForward_verSpeedMultiplier = 0.0f;

		unsigned int		mJumpBack_totalFrames = 0;
		float				mJumpBack_horSpeedMultiplier = 0.0f;
		float				mJumpBack_verSpeedMultiplier = 0.0f;
	};
}
