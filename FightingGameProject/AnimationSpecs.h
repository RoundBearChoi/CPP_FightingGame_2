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
		int32_t mX_TileCount = 0;
		int32_t mY_TileCount = 0;
		int32_t mTotalSprites = 0;
		int32_t mSkipFixedUpdates = 0;
		olc::vf2d mRenderSize = { 0.0f, 0.0f };
		olc::vf2d mRenderOffset = { 0.0f, 0.0f };
		RB::Sprites::SpriteEnum mSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		RB::Sprites::LoadedSprite* mLoadedSprite = nullptr;
		bool mPlayOnce = false;
	};
}