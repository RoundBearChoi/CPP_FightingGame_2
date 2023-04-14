#include "LoadedAnimation.h"

namespace RB::Render
{
	LoadedAnimation::LoadedAnimation(AnimationSpecs specs)
	{
		_animationSpecs = specs;
	}

	LoadedAnimation::~LoadedAnimation()
	{

	}

	AnimationSpecs LoadedAnimation::GetAnimationSpecs()
	{
		return _animationSpecs;
	}

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
}