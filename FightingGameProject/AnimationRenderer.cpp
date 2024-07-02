#include "AnimationRenderer.h"

#include "iCamController.h"

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

	void AnimationRenderer::RenderAnimation(const RenderSettings& renderSettings)
	{
		if (_animationSpecs.mSpriteType._value == RB::Sprites::SpriteType::NONE)
		{
			return;
		}

		if (RB::Cam::iCamController::Get() == nullptr)
		{
			return;
		}

		std::array<olc::vf2d, 4> points;

		olc::vf2d screenPos = renderSettings.mWorldPos;

		screenPos = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition(renderSettings.mWorldPos);

		float x = (float)screenPos.x;
		float y = (float)screenPos.y;

		float zoom = RB::Cam::iCamController::Get()->GetCamObj()->GetZoom();

		float width = renderSettings.mRenderSize.x * zoom;
		float height = renderSettings.mRenderSize.y * zoom;

		if (renderSettings.mFaceRight)
		{
			x += renderSettings.mRenderOffset.x * zoom;
			y += renderSettings.mRenderOffset.y * zoom;

			points[0] = { (float)x - (float)width / 2.0f, (float)y - (float)height };
			points[1] = { (float)x - (float)width / 2.0f, (float)y };
			points[2] = { (float)x + (float)width / 2.0f, (float)y };
			points[3] = { (float)x + (float)width / 2.0f, (float)y - (float)height };
		}
		else
		{
			x -= renderSettings.mRenderOffset.x * zoom;
			y += renderSettings.mRenderOffset.y * zoom;

			points[0] = { (float)x + (float)width / 2.0f, (float)y - (float)height };
			points[1] = { (float)x + (float)width / 2.0f, (float)y };
			points[2] = { (float)x - (float)width / 2.0f, (float)y };
			points[3] = { (float)x - (float)width / 2.0f, (float)y - (float)height };
		}

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(_animationSpecs.mLoadedSprite->GetDecal(), points, renderSettings.mSourcePos, renderSettings.mSourceSize);
	}
}
