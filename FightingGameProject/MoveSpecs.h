#pragma once

namespace RB::Players::Specs
{
	class MoveSpecs
	{
	public:
		CharacterType mCharacterType = CharacterType::NONE;
		size_t mJumpUp_totalFrames = 0;
		float_t mJumpUp_speedMultiplier = 0.0f;
	};
}