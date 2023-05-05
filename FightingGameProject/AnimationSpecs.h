#pragma once
#include "SpriteID.h"
#include "LoadedSprite.h"

namespace RB::Render
{
	class AnimationSpecs
	{
	public:
		AnimationSpecs() {}
		~AnimationSpecs() {}

	public:
		unsigned int mX_TileCount = 0;
		unsigned int mY_TileCount = 0;
		unsigned int mTotalSprites = 0;
		unsigned int mSkipFixedUpdates = 0;
		olc::vf2d mRenderSize = { 0.0f, 0.0f };
		RB::Sprites::SpriteID mSpriteID = RB::Sprites::SpriteID::NONE;
		RB::Sprites::LoadedSprite* mLoadedSprite = nullptr;
	};
}