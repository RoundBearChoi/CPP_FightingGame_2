#include "LoadedAnimation.h"

namespace RB::Render
{
	LoadedAnimation::LoadedAnimation(AnimationSpecs specs)
	{
		_animationSpecs = specs;

		//_xTileCount = xTileCount;
		//_yTileCount = yTileCount;
		//_totalSprites = totalSprites;
		//_skipFixedUpdates = skipFixedUpdates;
		//_spriteID = spriteID;
		//_loadedSprite = loadedSprite;
	}

	LoadedAnimation::~LoadedAnimation()
	{

	}

	AnimationSpecs LoadedAnimation::GetAnimationSpecs()
	{
		return _animationSpecs;
	}

	//RB::Sprites::SpriteID LoadedAnimation::GetSpriteID()
	//{
	//	return _spriteID;
	//}
	//
	//unsigned int LoadedAnimation::GetXTileCount()
	//{
	//	return _xTileCount;
	//}
	//
	//unsigned int LoadedAnimation::GetYTileCount()
	//{
	//	return _yTileCount;
	//}
	//
	//unsigned int LoadedAnimation::GetTotalSprites()
	//{
	//	return _totalSprites;
	//}

	void LoadedAnimation::RenderAnimation(AnimationRenderSettings renderSettings)
	{
		if (_animationSpecs.mSpriteID == RB::Sprites::SpriteID::NONE)
		{
			return;
		}

		std::array<olc::vf2d, 4> points;

		olc::vi2d screenPos = renderSettings.mWorldPos;

		if (RB::Cam::CurrentCam::CamExists())
		{
			screenPos = RB::Cam::CurrentCam::GetRelativePos(renderSettings.mWorldPos);
		}

		float x = (float)screenPos.x;
		float y = (float)screenPos.y;

		//temp
		float width = renderSettings.mRenderSize.x;
		float height = renderSettings.mRenderSize.y;

		points[0] = { (float)x - (float)width / 2.0f, (float)y - (float)height };
		points[1] = { (float)x - (float)width / 2.0f, (float)y };
		points[2] = { (float)x + (float)width / 2.0f, (float)y };
		points[3] = { (float)x + (float)width / 2.0f, (float)y - (float)height };

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(_animationSpecs.mLoadedSprite->GetDecal(), points, renderSettings.mSourcePos, renderSettings.mSourceSize);
	}

	//unsigned int LoadedAnimation::GetFixedUpdateSkipCount()
	//{
	//	return _skipFixedUpdates;
	//}
	//
	//olc::vi2d LoadedAnimation::GetSpriteSize()
	//{
	//	return _loadedSprite->GetSpriteSize();
	//}
}