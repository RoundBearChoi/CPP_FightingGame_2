#include "PlayerAnimationObj.h"

namespace RB::Render
{
	PlayerAnimationObj::PlayerAnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer)
	{
		_ownerPlayer = owner;
		_animationRenderer = animationRenderer;

		_skipFixedUpdates.SetSkipFrames(_animationRenderer->GetAnimationSpecs().mSkipFixedUpdates);
		_skipFixedUpdates.SetFunction(this, &PlayerAnimationObj::IncreaseAnimationIndex);
	}

	void PlayerAnimationObj::OnFixedUpdate()
	{
		_skipFixedUpdates.OnFixedUpdate();
	}

	void PlayerAnimationObj::IncreaseAnimationIndex()
	{
		if (_ownerPlayer->ManualAnimationUpdate())
		{
			return;
		}

		uint32_t totalSprites = _animationRenderer->GetAnimationSpecs().mTotalSprites;

		_currentIndex++;

		if (_currentIndex >= totalSprites)
		{
			_currentIndex = 0;
		}
	}

	olc::vf2d PlayerAnimationObj::GetSourceSize()
	{
		const AnimationSpecs& specs = _animationRenderer->GetAnimationSpecs();

		uint32_t xTiles = specs.mX_TileCount;
		uint32_t yTiles = specs.mY_TileCount;

		olc::vf2d sourceSize = { 0.0f, 0.0f };
		sourceSize.x = (float)specs.mLoadedSprite->GetSpriteSize().x / (float)xTiles;
		sourceSize.y = (float)specs.mLoadedSprite->GetSpriteSize().y / (float)yTiles;

		return sourceSize;
	}

	olc::vf2d PlayerAnimationObj::GetSourcePos(olc::vf2d sourceSize)
	{
		const AnimationSpecs& specs = _animationRenderer->GetAnimationSpecs();

		olc::vf2d sourcePos = { 0.0f, 0.0f };

		sourcePos.x = (_currentIndex % specs.mX_TileCount) * sourceSize.x;
		sourcePos.y = (int32_t)floor(_currentIndex / specs.mX_TileCount) * sourceSize.y;

		return sourcePos;
	}

	olc::vf2d PlayerAnimationObj::GetRenderSize()
	{
		return _animationRenderer->GetAnimationSpecs().mRenderSize;
	}

	olc::vf2d PlayerAnimationObj::GetRenderOffset()
	{
		return _animationRenderer->GetAnimationSpecs().mRenderOffset;
	}

	RB::Players::iPlayer* PlayerAnimationObj::GetPlayer()
	{
		return _ownerPlayer;
	}

	const AnimationSpecs& PlayerAnimationObj::GetAnimationSpecs()
	{
		return _animationRenderer->GetAnimationSpecs();
	}

	void PlayerAnimationObj::RenderAnimation()
	{
		if (_animationRenderer->GetAnimationSpecs().mSpriteID == RB::Sprites::SpriteID::NONE)
		{
			return;
		}

		AnimationRenderSettings renderSettings;

		renderSettings.mCurrentIndex = _currentIndex;
		renderSettings.mSourceSize = GetSourceSize();
		renderSettings.mSourcePos = GetSourcePos(renderSettings.mSourceSize);
		renderSettings.mRenderSize = GetRenderSize();
		renderSettings.mRenderOffset = GetRenderOffset();
		renderSettings.mWorldPos = _ownerPlayer->GetPosition();
		renderSettings.mPivotType = RB::Sprites::PivotType::BOTTOM_CENTER;
		renderSettings.mFaceRight = _ownerPlayer->OtherPlayerIsOnRightSide();

		_animationRenderer->RenderAnimation(renderSettings);
	}
}