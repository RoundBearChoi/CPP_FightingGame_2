#include "AnimationObj.h"
#include "RenderScaleMultiplierObj.h"
#include "RenderTransparencyObj.h"

namespace RB::Render
{
	AnimationObj::AnimationObj(Players::iPlayer* owner, AnimationRenderer* animationRenderer, Sprites::PivotType pivotType)
	{
		//std::cout << "constructing AnimationObj: " << animationRenderer->GetAnimationSpecs().mSpriteType._to_string() << ", player " << owner->GetPLAYER_TYPE_int() << std::endl;

		_ownerPlayer = owner;
		_animationRenderer = animationRenderer;
		_pivotType = pivotType;

		if (_animationRenderer != nullptr)
		{
			_skippedFixedUpdates.SetSkipFrames(_animationRenderer->GetAnimationSpecs().mSkipFixedUpdates);

			std::function<void()> func = std::bind(&AnimationObj::UpdateAnimationIndex, this);
			_skippedFixedUpdates.SetFunction(func);
		}

		// different default amounts
		_customRotations.SetLastAmount(0.0f);
		_customRenderScales.SetLastAmount(1.0f);
		_customTransparency.SetLastAmount(1.0f);
	}

	AnimationObj::~AnimationObj()
	{
		//std::cout << " - destructing AnimationObj: " << _animationRenderer->GetAnimationSpecs().mSpriteType._to_string() << ", player " << _ownerPLAYER_TYPE << std::endl;
	}

	void AnimationObj::OnFixedUpdate()
	{
		_skippedFixedUpdates.DoFixedUpdate();

		_customRenderScales.OnFixedUpdate();
		_customRotations.OnFixedUpdate();
		_customTransparency.OnFixedUpdate();

		_animationRenderer->OnFixedUpdate();
	}

	void AnimationObj::FaceRight(bool faceRight)
	{
		_faceRight = faceRight;
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

	RB::Vector2 AnimationObj::GetSourceSize()
	{
		const AnimationSpecs& specs = _animationRenderer->GetAnimationSpecs();

		unsigned int xTiles = specs.mX_TileCount;
		unsigned int yTiles = specs.mY_TileCount;

		RB::Vector2 sourceSize = { 0.0f, 0.0f };
		sourceSize.x = (float)specs.mLoadedSprite->GetSpriteSize().x / (float)xTiles;
		sourceSize.y = (float)specs.mLoadedSprite->GetSpriteSize().y / (float)yTiles;

		return sourceSize;
	}

	RB::Vector2 AnimationObj::GetSourcePos(RB::Vector2 sourceSize)
	{
		const AnimationSpecs& specs = _animationRenderer->GetAnimationSpecs();

		RB::Vector2 sourcePos = { 0.0f, 0.0f };

		sourcePos.x = (_currentIndex % specs.mX_TileCount) * sourceSize.x;
		sourcePos.y = (int)floor(_currentIndex / specs.mX_TileCount) * sourceSize.y;

		return sourcePos;
	}

	float AnimationObj::GetRenderScale()
	{
		return _animationRenderer->GetAnimationSpecs().mRenderScale;
	}

	RB::Vector2 AnimationObj::GetRenderOffset()
	{
		return _animationRenderer->GetAnimationSpecs().mRenderOffset;
	}

	Players::iPlayer* AnimationObj::GetPlayer()
	{
		return _ownerPlayer;
	}

	const AnimationSpecs& AnimationObj::GetAnimationSpecs() const
	{
		if (_animationRenderer != nullptr)
		{
			return _animationRenderer->GetAnimationSpecs();
		}
		else
		{
			return _emptySpecs;
		}
	}

	unsigned int AnimationObj::GetCurrentIndex()
	{
		return _currentIndex;
	}

	void AnimationObj::RenderAnimation()
	{
		if (_animationRenderer == nullptr)
		{
			return;
		}

		if (_animationRenderer->GetAnimationSpecs().mSpriteType._value == Sprites::SpriteType::NONE)
		{
			return;
		}

		RenderSettings renderSettings;

		renderSettings.mWorldPos = _worldPos;
		renderSettings.mCurrentIndex = _currentIndex;
		renderSettings.mPivotType = _pivotType;
		renderSettings.mSourceSize = GetSourceSize();
		renderSettings.mSourcePos = GetSourcePos(renderSettings.mSourceSize);
		renderSettings.mRenderScale = GetRenderScale() * GetRenderScaleMultiplier();
		renderSettings.mRotation = GetRotation();
		renderSettings.mTransparency = GetTransparency();
		renderSettings.mRenderOffset = GetRenderOffset();

		if (_ownerPlayer != nullptr)
		{
			renderSettings.mFaceRight = _ownerPlayer->IsFacingRight();
		}
		else
		{
			renderSettings.mFaceRight = _faceRight;
		}

		_animationRenderer->RenderAnimation(renderSettings);
	}

	void AnimationObj::SetWorldPos(const RB::Vector2& pos)
	{
		_worldPos = pos;
	}

	unsigned int AnimationObj::GetFixedUpdateCount()
	{
		return _skippedFixedUpdates.GetTotalFixedUpdateCount();
	}

	void AnimationObj::AddRenderScaleMultiplierObj(RenderScaleMultiplierObj* obj)
	{
		_customRenderScales.AddObj(obj);
	}

	void AnimationObj::AddRenderRotationObj(RenderRotationObj* obj)
	{
		_customRotations.AddObj(obj);
	}

	/// Transparency max is 1.0f
	void AnimationObj::AddRenderTransparency(RenderTransparencyObj* obj)
	{
		_customTransparency.AddObj(obj);
	}

	float AnimationObj::GetRenderScaleMultiplier()
	{
		return _customRenderScales.GetAmount();
	}

	float AnimationObj::GetRotation()
	{
		return _customRotations.GetAmount();
	}

	int AnimationObj::GetTransparency()
	{
		float percentage = _customTransparency.GetAmount();

		float result = percentage * 255.0f;

		int rounded = static_cast<int>(std::round(result));

		return rounded;
	}
}
