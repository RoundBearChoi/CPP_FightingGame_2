#include "AnimationRenderer.h"

namespace RB::Render
{
	AnimationRenderer::AnimationRenderer(AnimationSpecs specs)
	{
		_animationSpecs = specs;
	}

	const AnimationSpecs& AnimationRenderer::GetAnimationSpecs()
	{
		return _animationSpecs;
	}

	void AnimationRenderer::RenderAnimation(const AnimationRenderSettings& renderSettings)
	{
		if (_animationSpecs.mSpriteEnum == RB::Sprites::SpriteEnum::NONE)
		{
			return;
		}

		_getter_camController.OnUpdate();

		if (_getter_camController.GetController() == nullptr)
		{
			return;
		}

		std::array<olc::vf2d, 4> points;

		olc::vi2d screenPos = renderSettings.mWorldPos;

		screenPos = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(renderSettings.mWorldPos);

		float x = (float)screenPos.x;
		float y = (float)screenPos.y;

		//temp
		float width = renderSettings.mRenderSize.x;
		float height = renderSettings.mRenderSize.y;

		if (renderSettings.mFaceRight)
		{
			x += renderSettings.mRenderOffset.x;
			y += renderSettings.mRenderOffset.y;

			points[0] = { (float)x - (float)width / 2.0f, (float)y - (float)height };
			points[1] = { (float)x - (float)width / 2.0f, (float)y };
			points[2] = { (float)x + (float)width / 2.0f, (float)y };
			points[3] = { (float)x + (float)width / 2.0f, (float)y - (float)height };
		}
		else
		{
			x -= renderSettings.mRenderOffset.x;
			y += renderSettings.mRenderOffset.y;

			points[0] = { (float)x + (float)width / 2.0f, (float)y - (float)height };
			points[1] = { (float)x + (float)width / 2.0f, (float)y };
			points[2] = { (float)x - (float)width / 2.0f, (float)y };
			points[3] = { (float)x - (float)width / 2.0f, (float)y - (float)height };
		}

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(_animationSpecs.mLoadedSprite->GetDecal(), points, renderSettings.mSourcePos, renderSettings.mSourceSize);
	}
}