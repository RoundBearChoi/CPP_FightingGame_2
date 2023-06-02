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

		olc::vf2d screenPos = renderSettings.mWorldPos;

		screenPos = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(renderSettings.mWorldPos);

		float_t x = (float_t)screenPos.x;
		float_t y = (float_t)screenPos.y;

		float_t zoom = _getter_camController.GetController()->GetCamObj()->GetZoom();
		float_t width = renderSettings.mRenderSize.x * zoom;
		float_t height = renderSettings.mRenderSize.y * zoom;

		if (renderSettings.mFaceRight)
		{
			x += renderSettings.mRenderOffset.x;
			y += renderSettings.mRenderOffset.y;

			points[0] = { (float_t)x - (float_t)width / 2.0f, (float_t)y - (float_t)height };
			points[1] = { (float_t)x - (float_t)width / 2.0f, (float_t)y };
			points[2] = { (float_t)x + (float_t)width / 2.0f, (float_t)y };
			points[3] = { (float_t)x + (float_t)width / 2.0f, (float_t)y - (float_t)height };
		}
		else
		{
			x -= renderSettings.mRenderOffset.x;
			y += renderSettings.mRenderOffset.y;

			points[0] = { (float_t)x + (float_t)width / 2.0f, (float_t)y - (float_t)height };
			points[1] = { (float_t)x + (float_t)width / 2.0f, (float_t)y };
			points[2] = { (float_t)x - (float_t)width / 2.0f, (float_t)y };
			points[3] = { (float_t)x - (float_t)width / 2.0f, (float_t)y - (float_t)height };
		}

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(_animationSpecs.mLoadedSprite->GetDecal(), points, renderSettings.mSourcePos, renderSettings.mSourceSize);
	}
}