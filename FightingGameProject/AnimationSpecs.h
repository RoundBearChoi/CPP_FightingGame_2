#pragma once

#include "Vector2.h"
#include "SpriteType.h"
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
		RB::Vector2 mRenderOffset = { 0.0f, 0.0f };
		float mRenderScale = 0.0f;
		RB::Sprites::LoadedSprite* mLoadedSprite = nullptr;
		bool mPlayOnce = false;
		RB::Sprites::SpriteType mSpriteType = RB::Sprites::SpriteType::NONE;
	};
}
