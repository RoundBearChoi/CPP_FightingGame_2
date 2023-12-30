#pragma once

#include "SpriteEnum.h"

namespace RB::Collisions
{
	class PlayerBoxSpecs
	{
	public:
		PlayerBoxSpecs() = default;
		~PlayerBoxSpecs() = default;

	public:
		unsigned int mFrame = 0;
		float mOffsetX = 0.0f;
		float mOffsetY = 0.0f;
		float mWidth = 0.0f;
		float mHeight = 0.0f;
		RB::Sprites::SpriteEnum mSpriteType = RB::Sprites::SpriteEnum::NONE;
	};
}