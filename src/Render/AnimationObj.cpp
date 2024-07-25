#include "AnimationObj.h"

namespace RB::Render
{
	AnimationObj::AnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer, RB::Sprites::PivotType pivotType)
	{
		//std::cout << "constructing AnimationObj: " << animationRenderer->GetAnimationSpecs().mSpriteType._to_string() << ", player " << owner->GetPlayerID_int() << std::endl;

		_ownerPlayer = owner;
		_animationRenderer = animationRenderer;
		_pivotType = pivotType;

		if (_animationRenderer != nullptr)
		{
			_customFixedUpdate.SetSkipFrames(_animationRenderer->GetAnimationSpecs().mSkipFixedUpdates);
			_customFixedUpdate.SetFunction(this, &AnimationObj::UpdateAnimationIndex);
		}
	}

	AnimationObj::~AnimationObj()
	{
		//std::cout << " - destructing AnimationObj: " << _animationRenderer->GetAnimationSpecs().mSpriteType._to_string() << ", player " << _ownerPlayerID << std::endl;
	}

	void AnimationObj::OnFixedUpdate()
	{
		_customFixedUpdate.DoFixedUpdate();

		_animationRenderer->OnFixedUpdate();

		// update one at a time
		if (_vecMultiplierObjs.size() >= 1)
		{
			_vecMultiplierObjs[0].SetLastRenderScale(_lastRenderScaleMultiplier);
			_vecMultiplierObjs[0].OnFixedUpdate();
			_vecMultiplierObjs[0].AddProcessedFrame();

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

	RB::Players::iPlayer* AnimationObj::GetPlayer()
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
		renderSettings.mRenderScale = GetRenderScale() * GetRenderScaleMultiplier();
		renderSettings.mRotation = GetRotation();
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

	void AnimationObj::SetWorldPos(const RB::Vector2& pos)
	{
		_worldPos = pos;
	}

	unsigned int AnimationObj::GetFixedUpdateCount()
	{
		return _customFixedUpdate.GetTotalFixedUpdateCount();
	}

	void AnimationObj::AddRenderScaleMultiplierObj(RenderScaleMultiplierObj obj)
	{
		_vecMultiplierObjs.push_back(obj);
	}

	float AnimationObj::GetRenderScaleMultiplier()
	{
		if (_vecMultiplierObjs.size() == 0)
		{
			return _lastRenderScaleMultiplier; //1.0f;
		}
		else
		{
			float m = _vecMultiplierObjs[0].GetRenderScaleMultiplier();

			_lastRenderScaleMultiplier = m;

			return m;
		}
	}

	float AnimationObj::GetRotation()
	{
		if (_vecRotationObjs.size() == 0)
		{
			return _lastRotation;
		}
		else
		{
			float r = _vecRotationObjs[0].GetRotation();
			
			_lastRotation = r;
			
			return r;
		}
	}

	float AnimationObj::GetLastRenderScale()
	{
		return _lastRenderScaleMultiplier;
	}
}
