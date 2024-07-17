#include "AnimationRenderer.h"

namespace RB::Render
{
	AnimationRenderer::AnimationRenderer(AnimationSpecs specs)
	{
		_animationSpecs = specs;
	}

	void AnimationRenderer::OnFixedUpdate()
	{

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

		// get screen space x, y, width, height
		RB::Vector2 rel = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition(renderSettings.mWorldPos);

		float x = (float)rel.x;
		float y = (float)rel.y;

		float zoom = RB::Cam::iCamController::Get()->GetCamObj()->GetZoom();

		x += renderSettings.mRenderOffset.x * zoom;
		y += renderSettings.mRenderOffset.y * zoom;

		float width = renderSettings.mSourceSize.x * renderSettings.mRenderScale * zoom;
		float height = renderSettings.mSourceSize.y * renderSettings.mRenderScale * zoom;

		// get quads
		std::array<RB::Vector2, 4> points = RB::Sprites::GetQuadOnPivot(renderSettings.mPivotType, width, height, { x, y });

		// flip if necessary
		if (!renderSettings.mFaceRight)
		{
			points = RB::Sprites::FlipQuad(renderSettings.mPivotType, points);
		}

		// convert to vf2d
		std::array<olc::vf2d, 4> arrVF2D;

		for (int i = 0; i < points.size(); i++)
		{
			arrVF2D[i] = { points[i].x, points[i].y };
		}

		// render
		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(
			_animationSpecs.mLoadedSprite->GetDecal(),
			arrVF2D,
			olc::vf2d{ renderSettings.mSourcePos.x, renderSettings.mSourcePos.y },
			olc::vf2d{ renderSettings.mSourceSize.x, renderSettings.mSourceSize.y });

		//olc::Renderer::ptrPGE->SetDrawTarget(nullptr);
	}
}
