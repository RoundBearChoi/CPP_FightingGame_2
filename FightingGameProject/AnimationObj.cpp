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
		_customFixedUpdate.DoFixedUpdate();

		_animationRenderer->OnFixedUpdate();

		// update one at a time
		if (_vecMultiplierObjs.size() >= 1)
		{
			_vecMultiplierObjs[0].OnFixedUpdate();

			if (_vecMultiplierObjs[0].DoDelete())
			{
				_vecMultiplierObjs.erase(_vecMultiplierObjs.begin());
			}
		}
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

		CycleAnimationIndex();
	}

	void AnimationObj::ManualIncreaseAnimationIndex()
	{
		if (_currentIndex >= _animationRenderer->GetAnimationSpecs().mTotalSprites - 1)
		{
			_currentIndex = 0;
		}
		else
		{
			_currentIndex++;
		}
	}

	void AnimationObj::ManualDecreaseAnimationIndex()
	{
		if (_currentIndex <= 0)
		{
			_currentIndex = _animationRenderer->GetAnimationSpecs().mTotalSprites - 1;
		}
		else
		{
			_currentIndex--;
		}
	}

	void AnimationObj::CycleAnimationIndex()
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

		unsigned int xTiles = specs.mX_TileCount;
		unsigned int yTiles = specs.mY_TileCount;

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
		sourcePos.y = (int)floor(_currentIndex / specs.mX_TileCount) * sourceSize.y;

		return sourcePos;
	}

	float AnimationObj::GetRenderScale()
	{
		return _animationRenderer->GetAnimationSpecs().mRenderScale;
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

	unsigned int AnimationObj::GetCurrentIndex()
	{
		return _currentIndex;
	}

	void AnimationObj::RenderAnimation()
	{
		if (_animationRenderer->GetAnimationSpecs().mSpriteType._value == RB::Sprites::SpriteType::NONE)
		{
			return;
		}

		RenderSettings renderSettings;

		renderSettings.mWorldPos = _worldPos;
		renderSettings.mCurrentIndex = _currentIndex;
		renderSettings.mPivotType = _pivotType;
		renderSettings.mSourceSize = GetSourceSize();
		renderSettings.mSourcePos = GetSourcePos(renderSettings.mSourceSize);
		renderSettings.mRenderScale = GetRenderScale();
		renderSettings.mRenderScaleMultiplier = GetRenderScaleMultiplier();
		renderSettings.mRenderOffset = GetRenderOffset();

		if (_ownerPlayer != nullptr)
		{
			renderSettings.mFaceRight = _ownerPlayer->IsFacingRight();
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
	}

	unsigned int AnimationObj::GetFixedUpdateCount()
	{
		return _customFixedUpdate.GetTotalFixedUpdateCount();
	}

	void AnimationObj::AddMultiplierObj(RenderScaleMultiplierObj obj)
	{
		_vecMultiplierObjs.push_back(obj);
	}

	float AnimationObj::GetRenderScaleMultiplier()
	{
		if (_vecMultiplierObjs.size() == 0)
		{
			return 1.0f;
		}
		else
		{
			float m = _vecMultiplierObjs[0].GetRenderScaleMultiplier();
			return m;
		}
	}
}
