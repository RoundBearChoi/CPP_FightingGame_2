#include "AnimationObj.h"

namespace RB::Render
{
	AnimationObj::AnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer, RB::Sprites::PivotType pivotType)
	{
		_ownerPlayer = owner;
		_animationRenderer = animationRenderer;
		_pivotType = pivotType;

		_customFixedUpdate.SetSkipFrames(_animationRenderer->GetAnimationSpecs().mSkipFixedUpdates);
		_customFixedUpdate.SetFunction(this, &AnimationObj::UpdateAnimationIndex);
	}

	void AnimationObj::OnFixedUpdate()
	{
		_customFixedUpdate.OnFixedUpdate();
	}

	void AnimationObj::UpdateAnimationIndex()
	{
		if (_ownerPlayer != nullptr)
		{
			if (_ownerPlayer->ManualAnimationUpdate())
			{
				return;
			}
		}

		if (_animationRenderer->GetAnimationSpecs().mPlayOnce)
		{
			if (_currentIndex >= _animationRenderer->GetAnimationSpecs().mTotalSprites - 1)
			{
				_currentIndex = _animationRenderer->GetAnimationSpecs().mTotalSprites - 1;

				return;
			}
		}

		_currentIndex++;

		RecycleAnimationIndex();
	}

	void AnimationObj::ManualAddAnimationIndex(int32_t amount)
	{
		_currentIndex += amount;

		RecycleAnimationIndex();
	}

	void AnimationObj::RecycleAnimationIndex()
	{
		if (_currentIndex > _animationRenderer->GetAnimationSpecs().mTotalSprites - 1)
		{
			if (!_animationRenderer->GetAnimationSpecs().mPlayOnce)
			{
				_currentIndex = 0;
			}
		}

		else if (_currentIndex < 0)
		{
			_currentIndex = _animationRenderer->GetAnimationSpecs().mTotalSprites - 1;
		}
	}

	olc::vf2d AnimationObj::GetSourceSize()
	{
		const AnimationSpecs& specs = _animationRenderer->GetAnimationSpecs();

		uint32_t xTiles = specs.mX_TileCount;
		uint32_t yTiles = specs.mY_TileCount;

		olc::vf2d sourceSize = { 0.0f, 0.0f };
		sourceSize.x = (float)specs.mLoadedSprite->GetSpriteSize().x / (float)xTiles;
		sourceSize.y = (float)specs.mLoadedSprite->GetSpriteSize().y / (float)yTiles;

		return sourceSize;
	}

	olc::vf2d AnimationObj::GetSourcePos(olc::vf2d sourceSize)
	{
		const AnimationSpecs& specs = _animationRenderer->GetAnimationSpecs();

		olc::vf2d sourcePos = { 0.0f, 0.0f };

		sourcePos.x = (_currentIndex % specs.mX_TileCount) * sourceSize.x;
		sourcePos.y = (int32_t)floor(_currentIndex / specs.mX_TileCount) * sourceSize.y;

		return sourcePos;
	}

	olc::vf2d AnimationObj::GetRenderSize()
	{
		return _animationRenderer->GetAnimationSpecs().mRenderSize;
	}

	olc::vf2d AnimationObj::GetRenderOffset()
	{
		return _animationRenderer->GetAnimationSpecs().mRenderOffset;
	}

	RB::Players::iPlayer* AnimationObj::GetPlayer()
	{
		return _ownerPlayer;
	}

	const AnimationSpecs& AnimationObj::GetAnimationSpecs() const
	{
		return _animationRenderer->GetAnimationSpecs();
	}

	int32_t AnimationObj::GetCurrentIndex()
	{
		return _currentIndex;
	}

	void AnimationObj::RenderAnimation()
	{
		if (_animationRenderer->GetAnimationSpecs().mSpriteEnum == RB::Sprites::SpriteEnum::NONE)
		{
			return;
		}

		AnimationRenderSettings renderSettings;

		renderSettings.mWorldPos = _worldPos;
		renderSettings.mCurrentIndex = _currentIndex;
		renderSettings.mPivotType = _pivotType;
		renderSettings.mSourceSize = GetSourceSize();
		renderSettings.mSourcePos = GetSourcePos(renderSettings.mSourceSize);
		renderSettings.mRenderSize = GetRenderSize();
		renderSettings.mRenderOffset = GetRenderOffset();

		if (_ownerPlayer != nullptr)
		{
			renderSettings.mFaceRight = _ownerPlayer->IsFacingRight(); //OtherPlayerIsOnRightSide();
		}
		else
		{
			renderSettings.mFaceRight = true;
		}

		_animationRenderer->RenderAnimation(renderSettings);
	}

	void AnimationObj::SetWorldPos(const olc::vf2d& pos)
	{
		_worldPos = pos;

		//default render pivot is bottom center, so making adjustments
		if (_pivotType == RB::Sprites::PivotType::CENTER)
		{
			_worldPos.y += GetRenderSize().y * 0.5f;
		}
	}

	size_t AnimationObj::GetFixedUpdateCount()
	{
		return _customFixedUpdate.GetTotalFixedUpdateCount();
	}
}