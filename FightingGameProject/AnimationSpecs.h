#pragma once
#include "SpriteEnum.h"
#include "LoadedSprite.h"

namespace RB::Render
{
	class AnimationSpecs
	{
	public:
		AnimationSpecs() = default;
		~AnimationSpecs() = default;

	public:
		unsigned int mX_TileCount = 0;
		unsigned int mY_TileCount = 0;
		unsigned int mTotalSprites = 0;
		unsigned int mSkipFixedUpdates = 0;
		olc::vf2d mRenderSize = { 0.0f, 0.0f };
		olc::vf2d mRenderOffset = { 0.0f, 0.0f };
		RB::Sprites::LoadedSprite* mLoadedSprite = nullptr;
		bool mPlayOnce = false;
		RB::Sprites::SpriteType mSpriteEnum = RB::Sprites::SpriteType::NONE;
	};
}